#pragma once

#include <cstdint>
#include <cstring>
#include <string_view>

namespace simple_bin_signature_match{


struct SignaturePiece
{
    std::size_t                     ignoreNumber = 0; // Num bytes to skip from comparizon
    std::vector<std::uint8_t>       matchBytes      ; // Bytes must match exact

    void clear()
    {
        ignoreNumber = 0;
        matchBytes.clear();
    }

    bool empty() const
    {
        return matchBytes.empty() && ignoreNumber==0;
    }

    bool isExactMatch() const
    {
        return !matchBytes.empty();
    }
};

inline
std::size_t calcSignatureLen(std::vector<SignaturePiece>::const_iterator b, std::vector<SignaturePiece>::const_iterator e, std::size_t *pExactMatchCnt=0)
{
    std::size_t len = 0;
    std::size_t exactMatchCnt = 0;

    std::vector<SignaturePiece>::const_iterator it = b;
    for(; it!=e; ++it)
    {
        if (it->ignoreNumber)
        {
            len += it->ignoreNumber;
        }
        else
        {
            len           += it->matchBytes.size();
            exactMatchCnt += it->matchBytes.size();
        }
    }

    if (pExactMatchCnt)
    {
        *pExactMatchCnt = exactMatchCnt;
    }

    return len;
}

inline
std::size_t calcSignatureLen(const std::vector<SignaturePiece> &m, std::size_t *pExactMatchCnt=0)
{
    return calcSignatureLen(m.begin(), m.end(), pExactMatchCnt);
}


inline
bool signatureMatch(std::vector<SignaturePiece>::const_iterator b, std::vector<SignaturePiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    std::size_t matchLen = calcSignatureLen(b, e);
    if (matchLen>rawDataLen)
    {
        return false;
    }

    std::vector<SignaturePiece>::const_iterator it = b;
    for(; it!=e; ++it)
    {
        if (it->ignoreNumber)
        {
            pRawData += it->ignoreNumber;
        }
        else if (it->matchBytes.empty())
        {
            // Do nothing?
        }
        else
        {
            int cmpRes = std::memcmp((const void*)pRawData, (const void*)&it->matchBytes[0], it->matchBytes.size());
            if (cmpRes!=0)
            {
                return false;
            }

            pRawData += it->matchBytes.size();
        }
    }

    return true;

}

inline
bool signatureMatch(const std::vector<SignaturePiece> &m, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    return signatureMatch(m.begin(), m.end(), pRawData, rawDataLen);
}

//! Возвращает смещение найденного фрагмента от начала данных или (std::size_t)-1
inline
std::size_t findSignatureMatch(std::vector<SignaturePiece>::const_iterator b, std::vector<SignaturePiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    std::size_t offset = 0;

    std::vector<SignaturePiece>::const_iterator it = b;

    for(; it!=e && it->ignoreNumber!=0; ++it)
    {
        offset += it->ignoreNumber;
    }

    if (offset>=rawDataLen)
    {
        return (std::size_t)-1;
    }

    // Вообще нечего искать
    if (it==e)
    {
        return (std::size_t)-1;
    }
    
    // Что-то пошло не так, но assert или исключение низя, поэтому говорим, что не нашли
    if (it->matchBytes.empty())
    {
        return (std::size_t)-1;
    }

    auto rawView  = std::basic_string_view<std::uint8_t>(pRawData, rawDataLen);

    // Библиотечный алгоритм всяко шустрее, чем если сам буду колбасить
    auto foundPos = rawView.find(&it->matchBytes[0], offset, it->matchBytes.size());

    while(foundPos!=rawView.npos)
    {
        // Найдено начало, надо проверить всю последовательность
        if (signatureMatch(b, e, pRawData+foundPos, rawDataLen-foundPos))
            return foundPos;

        foundPos = rawView.find(&it->matchBytes[0], foundPos+1, it->matchBytes.size());
    }

    return (std::size_t)-1;
}

inline
std::size_t findSignatureMatch(const std::vector<SignaturePiece> &m, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    return findSignatureMatch(m.begin(), m.end(), pRawData, rawDataLen);
}

inline
std::vector<SignaturePiece> buildSignatureFromIdaSignatureString(const char* str, size_t *pParsedChars=0)
{
    auto trim = [](const char *s)
    {
         while(*s==' ') ++s;
         return s;
    };

    auto fromHexDigit = [](char ch) -> int
    {
        if (ch>='a' && ch<='f')
        {
            return ch - 'a' + 10;
        }
        if (ch>='A' && ch<='F')
        {
            return ch - 'A' + 10;
        }
        if (ch>='0' && ch<='9')
        {
            return ch - '0';
        }

        return -1;
    };


    std::vector<SignaturePiece> res;
    SignaturePiece curPiece;

    auto appendCurPieceAndClear = [&]()
    {
        if (!curPiece.empty())
        {
            res.emplace_back(curPiece);
        }

        curPiece.clear();
    };

    auto appendByte = [&](std::uint8_t b)
    {
        if (!curPiece.empty() && !curPiece.isExactMatch())
        {
            appendCurPieceAndClear();
        }

        curPiece.matchBytes.emplace_back(b);
    };


    const char* strOrg = str;

    auto finalize = [&]()
    {
        appendCurPieceAndClear();

        if (pParsedChars)
        {
            *pParsedChars = str - strOrg;
        }

        return res;
    };


    while(*str)
    {
        if (*str=='?')
        {
            if (curPiece.isExactMatch())
            {
                appendCurPieceAndClear();
            }

            curPiece.ignoreNumber++;

            str = trim(str+1); // Допустимо отсутствие пробелов
            continue;
        }

        int d = fromHexDigit(*str);
        if (d<0)
        {
            return finalize();
        }

        std::uint8_t curByte = (std::uint8_t)d;

        ++str;
        if (*str==0 || *str==' ')
        {
            appendByte(curByte); // Допустим байт из одной цифры
            if (*str)
            {
                str = trim(str+1);
            }
            continue;
        }

        if (*str=='?') // Допустима строка матча без пробелов
        {
            appendByte(curByte); // Допустим байт из одной цифры
            continue;
        }

        d = fromHexDigit(*str);
        if (d<0)
        {
            appendByte(curByte); // Допустим байт из одной цифры
            return finalize();
        }

        curByte <<= 4;
        curByte |= (std::uint8_t)d;
        
        appendByte(curByte);

        str = trim(str+1); // Допустимо отсутствие пробелов

    }

    return finalize();
}

inline
std::vector<SignaturePiece> buildSignatureFromIdaSignatureString(const std::string &str, size_t *pParsedChars=0)
{
    return buildSignatureFromIdaSignatureString(str.c_str(), pParsedChars);
}

inline
std::string formatToIdaSignatureString(const std::vector<SignaturePiece> &mpVec)
{
    std::string res;

    auto append = [&](char ch, char ch2=0)
    {
        if (!res.empty())
        {
            res.append(1, ' ');
        }

        res.append(1, ch);

        if (ch2!=0)
        {
            res.append(1, ch2);
        }
    };

    auto hexDigit = [](std::uint8_t d)
    {
        d &= 0x0F;
        return d>9 ? 'A'-10+d : '0'+d;
    };

    for(const auto &mp : mpVec)
    {
        if (mp.ignoreNumber)
        {
            for(auto i=0u; i!=mp.ignoreNumber; ++i)
            {
                append('?');
            }
        }
        else
        {
            for(auto b: mp.matchBytes)
            {
                append(hexDigit(b>>4), hexDigit(b));
            }
        }
    }

    return res;
}

//! Возвращает все найденные смещения найденного фрагмента от начала данных или (std::size_t)-1
inline
std::size_t findSignatureMatches( std::vector<SignaturePiece>::const_iterator b, std::vector<SignaturePiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen
                          , std::vector<std::uint8_t*> *pFoundAddresses=0
                          )
{
    const std::uint8_t *pRawDataBase = pRawData;

    std::vector<std::uint8_t*> foundAddresses;

    std::size_t matchCount = 0;

    std::size_t matchPos = 0;
    do
    {
        matchPos = findSignatureMatch(b, e, pRawData, rawDataLen);
        if (matchPos!=(std::size_t )-1)
        {
            const std::uint8_t *pMatchPos = pRawData + matchPos;
            std::size_t matchOffsetFromStart = (pMatchPos - pRawDataBase);
            foundAddresses.emplace_back((std::uint8_t*)pMatchPos);

            pRawData   += matchPos+1;
            rawDataLen -= matchPos+1;
            ++matchCount;
        }
    }
    while(matchPos!=(std::size_t)-1);

    if (pFoundAddresses)
    {
        *pFoundAddresses = foundAddresses;
    }

    return matchCount;
}

//! Возвращает все найденные смещения найденного фрагмента от начала данных или (std::size_t)-1
inline
std::size_t findSignatureMatches( const std::vector<SignaturePiece> &m, const std::uint8_t *pRawData, std::size_t rawDataLen
                          , std::vector<std::uint8_t*> *pFoundAddresses=0
                          )
{
    return findSignatureMatches(m.begin(), m.end(), pRawData, rawDataLen, pFoundAddresses);
}

//! Возвращает адрес единственного найденного положения, или 0, есил не найдено или больше одного вхождения
inline
const std::uint8_t* findUniqueSignatureMatch( std::vector<SignaturePiece>::const_iterator b, std::vector<SignaturePiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen )
{
    const std::uint8_t *pRawDataBase = pRawData;

    const std::uint8_t *pRes = 0;

    std::size_t matchCount = 0;

    std::size_t matchPos = 0;
    do
    {
        matchPos = findSignatureMatch(b, e, pRawData, rawDataLen);
        if (matchPos!=(std::size_t )-1)
        {
            const std::uint8_t *pMatchPos = pRawData + matchPos;
            std::size_t matchOffsetFromStart = (pMatchPos - pRawDataBase);
            pRes = pMatchPos;

            pRawData   += matchPos+1;
            rawDataLen -= matchPos+1;
            ++matchCount;
        }
    }
    while(matchPos!=(std::size_t)-1 && matchCount<2);

    if (matchCount>1)
    {
        return 0;
    }

    return pRes;
}

//! Возвращает адрес единственного найденного положения, или 0, есил не найдено или больше одного вхождения
inline
const std::uint8_t* findUniqueSignatureMatch(const std::vector<SignaturePiece> &m , const std::uint8_t *pRawData, std::size_t rawDataLen )
{
    return findUniqueSignatureMatch(m.begin(), m.end(), pRawData, rawDataLen);
}

inline
bool testSignatureMatch()
{
    std::vector<std::uint8_t> data = { 0x02, 0x15, 0x03, 0x61, 0xC9, 0x74, 0xEA, 0x21, 0xF3, 0xAD, 0x02, 0x15, 0x4C, 0x61, 0xC9, 0x5A, 0x88, 0x90, 0xD5, 0x65, 0xDB, 0x02, 0x74, 0xDB };

    std::vector<SignaturePiece> mp = buildSignatureFromIdaSignatureString("02 15 ? 61 C9");
    // { { 0, { 0x02, 0x15 } }
    // , { 1, {} }
    // , { 0, { 0x61, 0xC9 } }
    // };

    const std::uint8_t *pRawData = &data[0];
    std::size_t rawDataLen = data.size();

    std::size_t findCount = 0;

    std::size_t matchPos = 0;
    do
    {
        matchPos = findSignatureMatch(mp, pRawData, rawDataLen);
        if (matchPos!=(std::size_t )-1)
        {
            pRawData   += matchPos+1;
            rawDataLen -= matchPos+1;
            ++findCount;
        }
    }
    while(matchPos!=(std::size_t)-1);

    return true;
}



} // namespace simple_bin_signature_match


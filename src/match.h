#pragma once

#include <cstdint>
#include <cstring>
#include <string_view>


struct MatchPiece
{
    std::size_t                     ignoreSize; // Num bytes to skip from comparizon
    std::vector<std::uint8_t>       matchBytes; // Bytes must match exact
};

inline
std::size_t calcMatchLen(std::vector<MatchPiece>::const_iterator b, std::vector<MatchPiece>::const_iterator e)
{
    std::size_t len = 0;

    std::vector<MatchPiece>::const_iterator it = b;
    for(; it!=e; ++it)
    {
        if (it->ignoreSize)
        {
            len += it->ignoreSize;
        }
        else
        {
            len += it->matchBytes.size();
        }
    }

    return len;
}

inline
std::size_t calcMatchLen(const std::vector<MatchPiece> &m)
{
    return calcMatchLen(m.begin(), m.end());
}


inline
bool byteMatch(std::vector<MatchPiece>::const_iterator b, std::vector<MatchPiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    std::size_t matchLen = calcMatchLen(b, e);
    if (matchLen>rawDataLen)
    {
        return false;
    }

    std::vector<MatchPiece>::const_iterator it = e;
    for(; it!=e; ++it)
    {
        if (it->ignoreSize)
        {
            pRawData += it->ignoreSize;
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
bool byteMatch(const std::vector<MatchPiece> &m, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    return byteMatch(m.begin(), m.end(), pRawData, rawDataLen);
}

//! Возвращает смещение найденного фрагмента от начала данных или (std::size_t)-1
inline
std::size_t findMemMatch(std::vector<MatchPiece>::const_iterator b, std::vector<MatchPiece>::const_iterator e, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    std::size_t offset = 0;

    std::vector<MatchPiece>::const_iterator it = b;

    for(; it!=e && it->ignoreSize!=0; ++it)
    {
        offset += it->ignoreSize;
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
        if (byteMatch(b, e, pRawData, rawDataLen))
            return foundPos;

        foundPos = rawView.find(&it->matchBytes[0], foundPos+1, it->matchBytes.size());
    }

    return (std::size_t)-1;
}

inline
std::size_t findMemMatch(const std::vector<MatchPiece> &m, const std::uint8_t *pRawData, std::size_t rawDataLen)
{
    return findMemMatch(m.begin(), m.end(), pRawData, rawDataLen);
}

inline
bool testMemMatch()
{
    std::vector<std::uint8_t> data = { 0x02, 0x15, 0x03, 0x61, 0xC9, 0x74, 0xEA, 0x21, 0xF3, 0xAD, 0x02, 0x15, 0x4C, 0x61, 0xC9, 0x5A, 0x88, 0x90, 0xD5, 0x65, 0xDB, 0x02, 0x74, 0xDB };

    std::vector<MatchPiece> mp =
    { { 0, { 0x02, 0x15 } }
    , { 1, {} }
    , { 0, { 0x61, 0xC9 } }
    };

    const std::uint8_t *pRawData = &data[0];
    std::size_t rawDataLen = data.size();

    std::size_t findCount = 0;

    std::size_t matchPos = 0;
    do
    {
        matchPos = findMemMatch(mp, pRawData, rawDataLen);
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




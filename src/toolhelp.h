/******************************************************************************
Module:  Toolhelp.h
Notices: Copyright (c) 2000 Jeffrey Richter
******************************************************************************/

#pragma once

///////////////////////////////////////////////////////////////////////////

// This macro returns TRUE if a number is between two others
#define chINRANGE(low, Num, High) (((low) <= (Num)) && ((Num) <= (High)))

/////////////////////////// chDIMOF Macro /////////////////////////////////

// This macro evaluates to the number of elements in an array. 
#define chDIMOF(Array) (sizeof(Array) / sizeof(Array[0]))

#include <tlhelp32.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <cstdint>

#include "trace.h"
#include "helpers.h"

#pragma comment( lib, "advapi32" )

///////////////////////////////////////////////////////////////////////////

class LastErrorSaver
{
    DWORD errCode;

public:

    LastErrorSaver()
    : errCode(GetLastError())
    {}

    ~LastErrorSaver()
    {
        SetLastError(errCode);
    }
};


inline
std::uintptr_t ptrAlignDown(std::uintptr_t ptr)
{
    #if defined(WIN64) || defined(_WIN64)
        return ptr & 3;
    #else
        return ptr & 7;
    #endif
}

inline
BYTE* ptrAlignDown(BYTE* ptr)
{
    return reinterpret_cast<BYTE*>(ptrAlignDown(reinterpret_cast<std::uintptr_t>(ptr)));
}

inline
const BYTE* ptrAlignDown(const BYTE* ptr)
{
    return reinterpret_cast<BYTE*>(ptrAlignDown(reinterpret_cast<std::uintptr_t>(ptr)));
}

struct MemoryBlockInfo
{
    BYTE          *pbAddress;
    SIZE_T         blockSize;
    ULONG_PTR      hid; // heap id

    BYTE* getNextFreeAddress() const
    {
        return pbAddress+blockSize;
    }

    bool isAddressInBlock(const BYTE* ptr) const
    {
        return ptr>=pbAddress && ptr<getNextFreeAddress();
    }

    const BYTE* begin() const
    {
        return pbAddress;
    }

    const BYTE* end() const
    {
        return ptrAlignDown(getNextFreeAddress());
    }

};


struct ModuleInfo
{
    BYTE          *pbAddress;
    SIZE_T         blockSize;
    std::wstring   moduleName;
    std::wstring   moduleExeName;

    BYTE* getNextFreeAddress() const
    {
        return pbAddress+blockSize;
    }

    bool isAddressInBlock(const BYTE* ptr) const
    {
        return ptr>=pbAddress && ptr<getNextFreeAddress();
    }

    const BYTE* begin() const
    {
        return pbAddress;
    }

    const BYTE* end() const
    {
        return ptrAlignDown(getNextFreeAddress());
    }


    static
    std::wstring to_lower(std::wstring s)
    {
        for(auto &ch: s)
        {
            if (ch>='A' && ch<='Z')
                ch = ch - 'A' + 'a';
        }
    
        return s;
    }

    static
    std::wstring to_wide(const std::string &str)
    {
        std::wstring strRes; strRes.reserve(str.size());
        for(auto ch : str)
            strRes.append(1, (wchar_t)(unsigned char)ch);
        return strRes;
    }

    static
    std::wstring normalizeModuleName(const std::wstring &n)
    {
        return to_lower(n);
    }

    static
    std::wstring normalizeModuleName(const std::string &n)
    {
        return to_lower(to_wide(n));
    }

};


template<typename BlockInfo> inline
std::size_t findBlockByAddress(const std::vector<BlockInfo> &blocks, BYTE* ptr)
{
    for(std::size_t i=0u; i!=blocks.size(); ++i)
    {
        if (blocks[i].isAddressInBlock(ptr))
            return i;
    }

    return (std::size_t)-1;
}

inline
std::size_t findBlockByName(const std::vector<ModuleInfo> &blocks, std::wstring modName)
{
    modName = ModuleInfo::normalizeModuleName(modName);
    for(std::size_t i=0u; i!=blocks.size(); ++i)
    {
        if (blocks[i].moduleName==modName)
            return i;
    }
    return (std::size_t)-1;
}

inline
bool findModuleByAddress(const std::vector<ModuleInfo> &moduleInfoVec, BYTE* ptr, ModuleInfo &moduleInfo)
{
    std::size_t idx = findBlockByAddress(moduleInfoVec, ptr);
    if (idx==(std::size_t)-1)
    {
        return false;
    }

    moduleInfo = moduleInfoVec[idx];
    return true;
}

inline
bool findModuleByName(const std::vector<ModuleInfo> &moduleInfoVec, const std::wstring &modName, ModuleInfo &moduleInfo)
{
    std::size_t idx = findBlockByName(moduleInfoVec, modName);
    if (idx==(std::size_t)-1)
    {
        return false;
    }

    moduleInfo = moduleInfoVec[idx];
    return true;
}



void traceMemoryBlockInfo(const ModuleInfo &mi)
{
    WHATSAPP_TRACE(("Module: %s\n", to_ascii(mi.moduleName).c_str()));
    WHATSAPP_TRACE(("Path  : %s\n", to_ascii(mi.moduleExeName).c_str()));
    WHATSAPP_TRACE(("Base  : %s\n", formatPtr(mi.pbAddress).c_str()));
    WHATSAPP_TRACE(("Size  : %s (%zd)\n", formatPtr((void*)mi.blockSize).c_str(), mi.blockSize));
    WHATSAPP_TRACE(("Next  : %s\n", formatPtr(mi.getNextFreeAddress()).c_str()));
}

void traceMemoryBlockInfo(const MemoryBlockInfo &mi)
{
    WHATSAPP_TRACE(("Base  : %s\n", formatPtr(mi.pbAddress).c_str()));
    WHATSAPP_TRACE(("Size  : %s (%zd)\n", formatPtr((void*)mi.blockSize).c_str(), mi.blockSize));
    WHATSAPP_TRACE(("Next  : %s\n", formatPtr(mi.getNextFreeAddress()).c_str()));
}





class CToolhelp {
private:
   HANDLE m_hSnapshot;

public:

   bool snapshotValid() const
   {
       return m_hSnapshot != INVALID_HANDLE_VALUE;
   }

   CToolhelp(DWORD dwFlags = 0, DWORD dwProcessID = 0);
   ~CToolhelp();

   BOOL CreateSnapshot(DWORD dwFlags, DWORD dwProcessID = 0);
   
   BOOL ProcessFirst(PPROCESSENTRY32 ppe) const;
   BOOL ProcessNext(PPROCESSENTRY32 ppe) const;
   BOOL ProcessFind(DWORD dwProcessId, PPROCESSENTRY32 ppe) const;
   DWORD ProcessFind(const TCHAR *procName, PPROCESSENTRY32 ppe) const;

   BOOL ModuleFirst(PMODULEENTRY32 pme) const;
   BOOL ModuleNext(PMODULEENTRY32 pme) const;
   BOOL ModuleFind(PVOID pvBaseAddr, PMODULEENTRY32 pme) const;
   BOOL ModuleFind(PTSTR pszModName, PMODULEENTRY32 pme) const;
   
   BOOL ThreadFirst(PTHREADENTRY32 pte) const;
   BOOL ThreadNext(PTHREADENTRY32 pte) const;
   
   BOOL HeapListFirst(PHEAPLIST32 phl) const;
   BOOL HeapListNext(PHEAPLIST32 phl) const;
   int  HowManyHeaps() const;

   // Note: The heap block functions do not reference a snapshot and
   // just walk the process's heap from the beginning each time. Infinite 
   // loops can occur if the target process changes its heap while the
   // functions below are enumerating the blocks in the heap.
   static
   BOOL HeapFirst(PHEAPENTRY32 phe, DWORD dwProcessID, UINT_PTR dwHeapID);

   static
   BOOL HeapNext(PHEAPENTRY32 phe);

   static
   int  HowManyBlocksInHeap(DWORD dwProcessID, DWORD dwHeapId);

   //static
   BOOL IsAHeap(HANDLE hProcess, PVOID pvBlock, PDWORD pdwFlags);


   // New

   // Required valid snapshot
   template<typename THandler>
   bool enumerateProcesses(THandler handler)
   {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        auto processEnumRes = ProcessFirst(&pe);
        if (!processEnumRes)
        {
            return false;
        }
        while(processEnumRes)
        {
            pe.szExeFile[MAX_PATH-1] = 0;
            //std::wstring exeName = &pe.szExeFile[0];

            if (!handler(pe))
            {
                break;
            }
    
            pe.dwSize = sizeof(pe);
            processEnumRes = ProcessNext(&pe);
        }

        return true;
   }

   // Required valid snapshot
   template<typename THandler>
   bool enumerateThreads(THandler handler)
   {
        THREADENTRY32 the;
        the.dwSize = sizeof(the);

        auto enumRes = ThreadFirst(&the);
        if (!enumRes)
        {
            return false;
        }

        while(enumRes)
        {
            if (!handler(the))
            {
                break;
            }

            the.dwSize = sizeof(the);
            enumRes = ThreadNext(&the);
        }

        return true;
   }

   // Required valid snapshot
   std::vector<DWORD> getThreadList()
   {
       std::vector<DWORD> tids;
       enumerateThreads( [&](const THREADENTRY32 &the)
                         {
                             tids.emplace_back(the.th32ThreadID);
                             return true;
                         }
                       );
       return tids;
   }

   // Required valid snapshot
   template<typename THandler>
   bool enumerateModules(THandler handler)
   {
        MODULEENTRY32 me;
        me.dwSize = sizeof(me);

        auto enumRes = ModuleFirst(&me);
        if (!enumRes)
        {
            return false;
        }

        while(enumRes)
        {
            if (!handler(me))
            {
                break;
            }

            me.dwSize = sizeof(me);
            enumRes = ModuleNext(&me);
        }

        return true;
   }

   std::vector<ModuleInfo> getModulesInfo()
   {
       std::vector<ModuleInfo> miVec;
       enumerateModules( [&](const MODULEENTRY32 &me)
                         {
                             miVec.emplace_back( ModuleInfo{me.modBaseAddr, me.modBaseSize
                                               , ModuleInfo::normalizeModuleName(&me.szModule[0])
                                               , ModuleInfo::normalizeModuleName(&me.szExePath[0]) }
                                               );
                             return true;
                         }
                       );
       return miVec;
   }


   // Required valid snapshot
   template<typename THandler>
   bool enumerateHeaps(THandler handler)
   {
       HEAPLIST32 hl;
       hl.dwSize = sizeof(hl);
       BOOL fOk = HeapListFirst(&hl);
       for( ; fOk; fOk = HeapListNext(&hl))
       {
           if (!handler(hl))
               break;
           hl.dwSize = sizeof(hl);
       }
   
       return true;
   }

   std::vector<ULONG_PTR> getHeapList(DWORD processId=0)
   {
       std::vector<ULONG_PTR> hids;
       enumerateHeaps( [&](const HEAPLIST32 &hl)
                       {
                           if (!processId || processId==hl.th32ProcessID)
                           {
                               hids.emplace_back(hl.th32HeapID);
                           }
                           return true;
                       }
                     );
       return hids;
   }

   template<typename THandler>
   static
   bool enumerateHeapBlocks(THandler handler, DWORD processId, ULONG_PTR hid, std::size_t spinLimit=(std::size_t)-1)
   {
       HEAPENTRY32 he;
       he.dwSize = sizeof(he);
       BOOL fOk = HeapFirst(&he, processId, hid);
       for(std::size_t i=0u ; fOk; ++i, fOk = HeapNext(&he) )
       {
           if (spinLimit!=(std::size_t)-1 && i==spinLimit)
           {
               return false;
           }
           if (!handler(he))
               break;
           he.dwSize = sizeof(he);
       }

       return true;
   }

   static
   std::vector<MemoryBlockInfo> getHeapBlocks(DWORD processId, ULONG_PTR hid, std::size_t spinLimit=(std::size_t)-1)
   {
       std::vector<MemoryBlockInfo> mbiVec;
       enumerateHeapBlocks( [&](const HEAPENTRY32 &he)
                            {
                                mbiVec.emplace_back(MemoryBlockInfo{ (BYTE*)he.dwAddress, he.dwBlockSize, hid });
                                return true;
                            }
                          , processId, hid, spinLimit
                          );
       return mbiVec;
   }
   

   static
   DWORD threadSuspendResume(DWORD thId, bool resume=true)
   {
       HANDLE hThread = OpenThread( THREAD_SUSPEND_RESUME /* THREAD_ALL_ACCESS */ , FALSE /* no inherit */ , thId);
       if (hThread==0)
       {
           return (DWORD)-1;
       }

       DWORD res = resume ? ResumeThread(hThread) : SuspendThread(hThread);

       LastErrorSaver errSaver;
       CloseHandle(hThread);

       return res;
   }

   static
   bool threadsSuspendResume(const std::vector<DWORD> &tids, bool resume=true)
   {
       DWORD cutTid = GetCurrentThreadId();
       for(auto tid : tids)
       {
           if (cutTid!=tid) // prevent to suspend self
           {
               threadSuspendResume(tid, resume);
           }
       }

       return true;
   }




public:
   static BOOL EnableDebugPrivilege(HANDLE hToken, BOOL fEnable = TRUE);
   static BOOL EnableDebugPrivilege(BOOL fEnable = TRUE);
   static BOOL ReadProcessMemory(DWORD dwProcessID, LPCVOID pvBaseAddress, 
      PVOID pvBuffer, SIZE_T cbRead, SIZE_T *pszNumberOfBytesRead = NULL);
};

///////////////////////////////////////////////////////////////////////////

inline CToolhelp::CToolhelp(DWORD dwFlags, DWORD dwProcessID) {

   m_hSnapshot = INVALID_HANDLE_VALUE;
   CreateSnapshot(dwFlags, dwProcessID);
}

///////////////////////////////////////////////////////////////////////////

inline CToolhelp::~CToolhelp() {

   if (m_hSnapshot != INVALID_HANDLE_VALUE)
      CloseHandle(m_hSnapshot);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::CreateSnapshot(DWORD dwFlags, DWORD dwProcessID) {

   if (m_hSnapshot != INVALID_HANDLE_VALUE)
      CloseHandle(m_hSnapshot);

   if (dwFlags == 0) {
      m_hSnapshot = INVALID_HANDLE_VALUE;
   } else {
      m_hSnapshot = CreateToolhelp32Snapshot(dwFlags, dwProcessID);
   }
   return(m_hSnapshot != INVALID_HANDLE_VALUE);
}

///////////////////////////////////////////////////////////////////////////
inline BOOL CToolhelp::EnableDebugPrivilege(HANDLE hToken, BOOL fEnable)
{
    BOOL fOk = FALSE;    // Assume function fails

    // Attempt to modify the "Debug" privilege
    LUID luid;
    
    if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
    {
        return FALSE;
    }

    TOKEN_PRIVILEGES tp;
    TOKEN_PRIVILEGES tpPrevious;
    DWORD cbPrevious = sizeof(TOKEN_PRIVILEGES);

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Luid = luid;
    tp.Privileges[0].Attributes = 0;
    if (!AdjustTokenPrivileges(hToken, FALSE /* DisableAllPrivileges */ , &tp, sizeof(tp), &tpPrevious, &cbPrevious))
    {
        return FALSE;
    }

    tpPrevious.PrivilegeCount = 1;
    tpPrevious.Privileges[0].Luid = luid;
    if(fEnable)
    {
        tpPrevious.Privileges[0].Attributes |= (SE_PRIVILEGE_ENABLED);
    }
    else
    {
        tpPrevious.Privileges[0].Attributes ^= (SE_PRIVILEGE_ENABLED & tpPrevious.Privileges[0].Attributes);
    }

    if (!AdjustTokenPrivileges(hToken, FALSE, &tpPrevious, cbPrevious, NULL, NULL))
    {
        return FALSE;
    }

    fOk = (GetLastError() == ERROR_SUCCESS);
     
    return fOk;
}

inline BOOL CToolhelp::EnableDebugPrivilege(BOOL fEnable)
{
   // Enabling the debug privilege allows the application to see
   // information about service applications
   HANDLE hToken;

   // https://gist.github.com/trietptm/0e18564bb44be46abdc6d7d0843e5e0f
   // Try to open this process's access token
   if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) // TOKEN_QUERY - newly added 
       return FALSE;

   //hToken = GetCurrentThreadToken();
   if (hToken==0)
   {
       return FALSE;
   }

   {
      BOOL res = EnableDebugPrivilege(hToken, fEnable);

      auto err = GetLastError();
      CloseHandle(hToken);
      SetLastError(err);
      return res;
   }

   return FALSE;
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ReadProcessMemory(DWORD dwProcessID, 
   LPCVOID pvBaseAddress, PVOID pvBuffer, SIZE_T cbRead, SIZE_T *pszNumberOfBytesRead)
{
   return Toolhelp32ReadProcessMemory(dwProcessID, pvBaseAddress, pvBuffer, 
                                      cbRead, pszNumberOfBytesRead);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ProcessFirst(PPROCESSENTRY32 ppe) const {

   BOOL fOk = Process32First(m_hSnapshot, ppe);
   if (fOk && (ppe->th32ProcessID == 0))
      fOk = ProcessNext(ppe); // Remove the "[System Process]" (PID = 0)
   return(fOk);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ProcessNext(PPROCESSENTRY32 ppe) const {

   BOOL fOk = Process32Next(m_hSnapshot, ppe);
   if (fOk && (ppe->th32ProcessID == 0))
      fOk = ProcessNext(ppe); // Remove the "[System Process]" (PID = 0)
   return(fOk);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ProcessFind(DWORD dwProcessId, PPROCESSENTRY32 ppe) 
   const {

   BOOL fFound = FALSE;
   for (BOOL fOk = ProcessFirst(ppe); fOk; fOk = ProcessNext(ppe)) {
      fFound = (ppe->th32ProcessID == dwProcessId);
      if (fFound) break;
   }
   return(fFound);
}

///////////////////////////////////////////////////////////////////////////

inline DWORD CToolhelp::ProcessFind(const TCHAR *procName, PPROCESSENTRY32 ppe) const
{
    if (!procName) return 0;
    for (BOOL fOk = ProcessFirst(ppe); fOk; fOk = ProcessNext(ppe))
        {
         if (!lstrcmpi(ppe->szExeFile, procName)) return ppe->th32ProcessID;
        }
    return 0;
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ModuleFirst(PMODULEENTRY32 pme) const {

   return(Module32First(m_hSnapshot, pme));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ModuleNext(PMODULEENTRY32 pme) const {

   return(Module32Next(m_hSnapshot, pme));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ModuleFind(PVOID pvBaseAddr, PMODULEENTRY32 pme) const {

   BOOL fFound = FALSE;
   for (BOOL fOk = ModuleFirst(pme); fOk; fOk = ModuleNext(pme)) {
      fFound = (pme->modBaseAddr == pvBaseAddr);
      if (fFound) break;
   }
   return(fFound);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ModuleFind(PTSTR pszModName, PMODULEENTRY32 pme) const {
   BOOL fFound = FALSE;
   for (BOOL fOk = ModuleFirst(pme); fOk; fOk = ModuleNext(pme)) {
      fFound = (lstrcmpi(pme->szModule,  pszModName) == 0) || 
               (lstrcmpi(pme->szExePath, pszModName) == 0);
      if (fFound) break;
   }
   return(fFound);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ThreadFirst(PTHREADENTRY32 pte) const {

   return(Thread32First(m_hSnapshot, pte));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::ThreadNext(PTHREADENTRY32 pte) const {

   return(Thread32Next(m_hSnapshot, pte));
}

///////////////////////////////////////////////////////////////////////////

inline int CToolhelp::HowManyHeaps() const {

   int nHowManyHeaps = 0;
   HEAPLIST32 hl = { sizeof(hl) };
   for (BOOL fOk = HeapListFirst(&hl); fOk; fOk = HeapListNext(&hl))
      nHowManyHeaps++;
   return(nHowManyHeaps);
}

///////////////////////////////////////////////////////////////////////////

inline int CToolhelp::HowManyBlocksInHeap(DWORD dwProcessID, DWORD dwHeapID)
{
   int nHowManyBlocksInHeap = 0;
   HEAPENTRY32 he = { sizeof(he) };
   BOOL fOk = HeapFirst(&he, dwProcessID, dwHeapID);
   for (; fOk; fOk = HeapNext(&he))
      nHowManyBlocksInHeap++;
   return(nHowManyBlocksInHeap);
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::HeapListFirst(PHEAPLIST32 phl) const {

   return(Heap32ListFirst(m_hSnapshot, phl));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::HeapListNext(PHEAPLIST32 phl) const {

   return(Heap32ListNext(m_hSnapshot, phl));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::HeapFirst(PHEAPENTRY32 phe, DWORD dwProcessID, UINT_PTR dwHeapID)
{
   return(Heap32First(phe, dwProcessID, dwHeapID));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::HeapNext(PHEAPENTRY32 phe)
{
   return(Heap32Next(phe));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::IsAHeap(HANDLE hProcess, PVOID pvBlock, PDWORD pdwFlags)
{
   HEAPLIST32 hl = { sizeof(hl) };
   for (BOOL fOkHL = HeapListFirst(&hl); fOkHL; fOkHL = HeapListNext(&hl)) {
      HEAPENTRY32 he = { sizeof(he) };
      BOOL fOkHE = HeapFirst(&he, hl.th32ProcessID, hl.th32HeapID);
      for (; fOkHE; fOkHE = HeapNext(&he)) {
         MEMORY_BASIC_INFORMATION mbi;
         VirtualQueryEx(hProcess, (PVOID) he.dwAddress, &mbi, sizeof(mbi));
         if (chINRANGE(mbi.AllocationBase, pvBlock, 
            (PBYTE) mbi.AllocationBase + mbi.RegionSize)) {

            *pdwFlags = hl.dwFlags;
            return(TRUE);
         }
      }
   }
   return(FALSE);
}

//////////////////////////////// End of File //////////////////////////////////

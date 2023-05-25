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

#pragma comment( lib, "advapi32" )

///////////////////////////////////////////////////////////////////////////

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
   BOOL HeapFirst(PHEAPENTRY32 phe, DWORD dwProcessID, 
      UINT_PTR dwHeapID) const;
   BOOL HeapNext(PHEAPENTRY32 phe) const;
   int  HowManyBlocksInHeap(DWORD dwProcessID, DWORD dwHeapId) const;
   BOOL IsAHeap(HANDLE hProcess, PVOID pvBlock, PDWORD pdwFlags) const;

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

inline int CToolhelp::HowManyBlocksInHeap(DWORD dwProcessID, 
   DWORD dwHeapID) const {

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

inline BOOL CToolhelp::HeapFirst(PHEAPENTRY32 phe, DWORD dwProcessID, 
   UINT_PTR dwHeapID) const {

   return(Heap32First(phe, dwProcessID, dwHeapID));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::HeapNext(PHEAPENTRY32 phe) const {

   return(Heap32Next(phe));
}

///////////////////////////////////////////////////////////////////////////

inline BOOL CToolhelp::IsAHeap(HANDLE hProcess, PVOID pvBlock, 
   PDWORD pdwFlags) const {

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
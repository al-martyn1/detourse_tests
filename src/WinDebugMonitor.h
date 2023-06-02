//////////////////////////////////////////////////////////////
//
//         File: WinDebugMonitor.h
//  Description: Interface of class CWinDebugMonitor
//      Created: 2007-12-6
//       Author: Ken Zhang
//       E-Mail: cpp.china@hotmail.com
//
//////////////////////////////////////////////////////////////

#ifndef __WIN_DEBUG_BUFFER_H__
#define __WIN_DEBUG_BUFFER_H__

#include <windows.h>
#include <atlbase.h>
#include <atlstr.h>

#include <string>
#include <unordered_set>

class CWinDebugMonitor
{
private:
	enum {
		TIMEOUT_WIN_DEBUG	=	100,
	};

	struct dbwin_buffer
	{
		DWORD   dwProcessId;
		char    data[4096-sizeof(DWORD)];
	};

    std::unordered_set<DWORD> processFilters; // by ID

private:
	HANDLE m_hDBWinMutex;
	HANDLE m_hDBMonBuffer;
	HANDLE m_hEventBufferReady;
	HANDLE m_hEventDataReady;

	HANDLE m_hWinDebugMonitorThread;
	BOOL m_bWinDebugMonStopped;
	struct dbwin_buffer *m_pDBBuffer;

private:
	DWORD Initialize();
	void Unintialize();
	DWORD WinDebugMonitorProcess();
	static DWORD WINAPI WinDebugMonitorThread(void *pData);

public:

    void PidAdd(DWORD pid)    { processFilters.insert(pid); }
    void PidRemove(DWORD pid) { processFilters.erase (pid); }
    bool PidTest(DWORD pid)   { if (processFilters.empty()) return true; return processFilters.find(pid)!=processFilters.end(); }

	CWinDebugMonitor();
	~CWinDebugMonitor();

public:
	virtual void OutputWinDebugString(DWORD pid, const char *str) {};
};

#endif

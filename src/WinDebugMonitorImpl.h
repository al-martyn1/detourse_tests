
#include "WinDebugMonitor.h"
#include <conio.h>

// https://www.codeproject.com/Articles/23776/Mechanism-of-OutputDebugString

class CWinDebugMonitorImpl : public CWinDebugMonitor
{
public:
	virtual void OutputWinDebugString(DWORD pid, const char *str)
	{
		printf("[%*I32u] %s", 6, pid, str);
	};
};


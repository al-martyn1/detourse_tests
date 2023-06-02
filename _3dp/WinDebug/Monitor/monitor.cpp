
#include "WinDebugMonitor.h"
#include <conio.h>

class Monitor : public CWinDebugMonitor
{
public:
	virtual void OutputWinDebugString(DWORD pid, const char *str)
	{
		printf("%s", str);
	};
};

void main()
{
	printf("Win Debug Monitor Tool\n");
	printf("----------------------\n");
	Monitor mon;
	getch();
}

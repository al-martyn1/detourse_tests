// output.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;

	printf("Press any key to stop calling OutputDebugString......\n");

	while (!kbhit()) {
		TCHAR buf[64];
		_stprintf(buf, _T("Message from process %d, msg id: %d\n"), ::GetCurrentProcessId(), ++i);
		OutputDebugString(buf);
	}

	printf("Total %d messages sent.\n", i);

	return 0;
}


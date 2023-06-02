#pragma once


// https://gist.github.com/mmozeiko/bfe0ce5762c496f92d8c775983c41694
// See also
// https://www.codeproject.com/Articles/23776/Mechanism-of-OutputDebugString
// https://learn.microsoft.com/en-us/sysinternals/downloads/debugview

#define Assert(x) do { if (!(x)) __debugbreak(); } while (0)

struct OdsBuffer
{
    DWORD process_id;
    char  data[4096 - sizeof(DWORD)];
};


static OdsBuffer* ods_buffer;

DWORD odsHandleProcessId = 0;


static HANDLE ods_data_ready;
static HANDLE ods_buffer_ready;

static DWORD WINAPI ods_proc(LPVOID arg)
{
    DWORD ret = 0;

    HANDLE hStderr = GetStdHandle(STD_ERROR_HANDLE);
    Assert(hStderr);

    for (;;)
    {
        //std::cout << "ods_proc loop\n";

        SetEvent(ods_buffer_ready);

        DWORD wait = WaitForSingleObject(ods_data_ready, INFINITE);
        Assert(wait == WAIT_OBJECT_0);

        DWORD length = 0;
        while (length < sizeof(ods_buffer->data) && ods_buffer->data[length] != 0)
        {
            length++;
        }

        if (length != 0)
        {
            if (odsHandleProcessId==0 || odsHandleProcessId==ods_buffer->process_id)
            {
                DWORD written;
                WriteFile(hStderr, ods_buffer->data, length, &written, NULL);
            }
        }
    }
}

inline
void ods_capture()
{
    if (IsDebuggerPresent())
    {
        return;
    }

    HANDLE file = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(*ods_buffer), "DBWIN_BUFFER");
    Assert(file != INVALID_HANDLE_VALUE);

    ods_buffer = (OdsBuffer*)MapViewOfFile(file, SECTION_MAP_READ, 0, 0, 0);
    Assert(ods_buffer);

    ods_buffer_ready = CreateEventA(NULL, FALSE, FALSE, "DBWIN_BUFFER_READY");
    Assert(ods_buffer_ready);

    ods_data_ready = CreateEventA(NULL, FALSE, FALSE, "DBWIN_DATA_READY");
    Assert(ods_data_ready);

    HANDLE thread = CreateThread(NULL, 0, ods_proc, NULL, 0, NULL);
    Assert(thread);
}


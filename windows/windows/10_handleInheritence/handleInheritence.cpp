#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<tchar.h>


void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;
	HANDLE hfile;


	ZeroMemory(&si1, sizeof(si1));//intialising 0 to all the bytes of data
	si1.cb = sizeof(si1);

	ZeroMemory(&pi1, sizeof(pi1));

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;


	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesnot exist.Error (%d)\n"), GetLastError());
		getchar();
		return;

	}
	_tprintf(_T("File(%s) opened succesfully"), argv[1]);

	if (argc != 2)
	{
		printf("Usage\n");
		getchar();
		return;
	}

	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create Process error (%d)\n", GetLastError());
		getchar();
		return;
	}

	printf("Handle of the process1:%d\n", pi1.hProcess);
	printf("Process ID of proces1:%d\n", pi1.dwProcessId);
	printf("Process thread of process1:%d\n", pi1.dwThreadId);

	CloseHandle(pi1.hThread);
	CloseHandle(pi1.hProcess);

	//CloseHandle(hproc);

	getchar();
}
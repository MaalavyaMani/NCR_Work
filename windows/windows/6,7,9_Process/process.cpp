#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;

	ZeroMemory(&si1, sizeof(si1));//intialising 0 to all the bytes of data
	si1.cb = sizeof(si1);
	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);

	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&pi2, sizeof(pi2));

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	if (argc != 3)
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
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
	{
		printf("Create Process error (%d)\n", GetLastError());
		getchar();
		return;
	}
	printf("Handle of the process1:%d\n", pi1.hProcess);
	printf("Process ID of proces1:%d\n", pi1.dwProcessId);
	printf("Process thread of process1:%d\n", pi1.dwThreadId);

	printf("Handle of the process2:%d\n", pi2.hProcess);
	printf("Process ID of proces2:%d\n", pi2.dwProcessId);
	printf("Process thread of process2:%d\n", pi2.dwThreadId);

	printf("Process current process ID:%d\n", GetCurrentProcessId());//main function id
	printf("Process current thread ID:%d\n", GetCurrentThreadId());//primary thread of main function id
	printf("Process1 process ID:%d\n", GetProcessId(pi1.hProcess));//notepad process id
	printf("Process1 thread ID ID:%d\n", GetThreadId(pi1.hThread));//notepad thread id
	printf("Process1 process ID:%d\n", GetProcessIdOfThread(pi1.hThread));//process 1 thread's process id
	printf("Process2 process ID:%d\n", GetProcessId(pi2.hProcess));//calci process id
	printf("Process2 thread ID ID:%d\n", GetThreadId(pi2.hThread));//calci thread id
	printf("Process2 process ID:%d\n", GetProcessIdOfThread(pi2.hThread));//process 2 thread's process id

	CloseHandle(pi1.hThread);
	CloseHandle(pi1.hProcess);
	CloseHandle(pi2.hThread);
	CloseHandle(pi2.hProcess);
	//CloseHandle(hproc);

	getchar();
}
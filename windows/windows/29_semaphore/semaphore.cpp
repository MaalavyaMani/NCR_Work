#include<windows.h>
#include<stdio.h>
#define MAX_SEM_COUNT 2
#define ThreadCount 4
HANDLE ghSemaphore;
DWORD WINAPI ThreadProc(LPVOID);

int main(void) {
	HANDLE aThread[ThreadCount];
	DWORD ThreadID;
	int i;
	ghSemaphore = CreateSemaphore(NULL, MAX_SEM_COUNT, MAX_SEM_COUNT, NULL);
	if (ghSemaphore == NULL) {
		printf("Create Semaphore error %d\n", GetLastError());
		return 1;
	}

	for (i = 0; i < ThreadCount; i++) {
		aThread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, NULL, 0, &ThreadID);

		if (aThread[i] == NULL) {
			printf("Create Semaphore error %d\n", GetLastError());
			return 1;
		}
	}

	WaitForMultipleObjects(ThreadCount, aThread, TRUE, INFINITE);
	for (i = 0; i <= ThreadCount; i++)
		CloseHandle(aThread[i]);
	CloseHandle(ghSemaphore);
	getchar();
	return 0;
}
	DWORD WINAPI ThreadProc(LPVOID lpParam) {
		UNREFERENCED_PARAMETER(lpParam);
		DWORD dwWaitResult;
		

		dwWaitResult = WaitForSingleObject(ghSemaphore, 0L);
			switch (dwWaitResult) {
			case WAIT_OBJECT_0:
					printf("Thread %d: wait succeeded\n", GetCurrentThreadId());
				
					Sleep(200);

					if (!ReleaseSemaphore(ghSemaphore, 1, NULL)) {
						printf("ReleaseSemaphore error:%d\n", GetLastError());
					}
					break;

				case WAIT_TIMEOUT:
					printf("Thread %d: wait timed out\n", GetCurrentThreadId());
					break;
			}
		
		return TRUE;
		
	}
	
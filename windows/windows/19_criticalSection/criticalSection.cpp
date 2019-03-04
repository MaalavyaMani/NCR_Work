#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>

const int count = 100;
int g_sum = 0;
CRITICAL_SECTION g_cs;

DWORD WINAPI FirstThread(LPVOID lparam) {
	EnterCriticalSection(&g_cs);
	g_sum = 0;
	for (int i = 1; i <= count; i++) {
		g_sum += i;
	}
	printf("g_sum=%d\n", g_sum);
	LeaveCriticalSection(&g_cs);
	return g_sum;
}

DWORD WINAPI SecondThread(LPVOID lparam) {
	EnterCriticalSection(&g_cs);
	//g_sum = 0;
	for (int i = 1; i <= count; i++) {
		g_sum += i;
	}

	printf("g_sum=%d\n", g_sum);
	LeaveCriticalSection(&g_cs);
	return g_sum;
}

int main() {

	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE arry_hand[2];


	InitializeCriticalSection(&g_cs);
	InitializeCriticalSectionAndSpinCount(&g_cs,5000);
	
	
		hThread1 = CreateThread(NULL, 0, FirstThread, NULL, 0, &thID1);
		if (hThread1 == NULL) {
			printf("unable to create thread\n");
			return 1;
		}
		hThread2 = CreateThread(NULL, 0, SecondThread, NULL, 0, &thID2);
		if (hThread2 == NULL) {
			printf("unable to create thread\n");
			return 1;
		}
	
	arry_hand[0] = hThread1;
	arry_hand[1] = hThread2;

	WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);
	
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	DeleteCriticalSection(&g_cs);

	printf("waiting for user input before exiting the process\n");

	getchar();
}
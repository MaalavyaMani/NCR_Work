#include <iostream>
#include <cstdlib>
#include <queue>
#include <Windows.h>
#include <tchar.h>

using namespace std;
SRWLOCK g_srwlock;
CONDITION_VARIABLE g_cvReadyToConsume;
CONDITION_VARIABLE g_cvReadyToProduce;
volatile LONG isRunning = TRUE;
HANDLE g_hThreads[MAXIMUM_WAIT_OBJECTS];
int g_numThreads = 0;
#define QSIZELIMIT 5
struct object
{
	int ThreadNo;
	int element;
}obj;
queue <object> gSharedQ;
DWORD WINAPI WriterThread(LPVOID lparam)
{
	int ThreadNo = PtrToUlong(lparam);
	int element;
	for (element = 1; isRunning; element++)
	{
		object obj = { ThreadNo, element };

		AcquireSRWLockExclusive(&g_srwlock);
		if (gSharedQ.size() >= QSIZELIMIT && isRunning)
		{
			cout << "Writer Thread" << ThreadNo << "\n"<< "Q is full. Can't produce" << element << endl;
			SleepConditionVariableSRW(&g_cvReadyToProduce, &g_srwlock, INFINITE, 0);
		}
		if (!isRunning)
		{
			cout << "Writer Thread" << ThreadNo<<"\n" << "bye" << endl;
			ReleaseSRWLockExclusive(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToProduce);
			return 0;
		}
		else
		{
			gSharedQ.push(obj);
			cout << "Writer Thread" << ThreadNo <<"\n"<< "Produced" << element << endl;
			ReleaseSRWLockExclusive(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToConsume);
			Sleep(1500);
		}
		cout << "Writer Thread" << ThreadNo <<"\n"<< "bye" << endl;
	}
}
DWORD WINAPI ReaderThread(LPVOID lparam)
{
	int ThreadNo = PtrToUlong(lparam);
	for (int element = 1; isRunning; element++)
	{
		AcquireSRWLockExclusive(&g_srwlock);
		if (gSharedQ.empty() && isRunning)
		{
			cout << "Reader Thread" << ThreadNo<<"\n" << "Nothing to consume\n";
			SleepConditionVariableSRW(&g_cvReadyToConsume, &g_srwlock, INFINITE, CONDITION_VARIABLE_LOCKMODE_SHARED);
		}
		if (!isRunning)
		{
			cout << "ReaderThread" << ThreadNo << "\n"<<"bye\n" << endl;
			ReleaseSRWLockShared(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToConsume);
			return 0;
		}
		else
		{
			object obj = gSharedQ.front();
			cout << "Reader Thread consumed\n";
			gSharedQ.pop();
			ReleaseSRWLockShared(&g_srwlock);
			WakeAllConditionVariable(&g_cvReadyToProduce);
		}
		Sleep(2500);
	}
}
DWORD WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:
		cout << "[Ctrl]+C\n";
		InterlockedExchange(&isRunning, FALSE);
		WakeAllConditionVariable(&g_cvReadyToConsume);
		WakeAllConditionVariable(&g_cvReadyToProduce);
		return TRUE;
	default:
		return FALSE;
	}
}
int main()
{
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, TRUE);
	InitializeSRWLock(&g_srwlock);
	InitializeConditionVariable(&g_cvReadyToConsume);
	InitializeConditionVariable(&g_cvReadyToProduce);
	DWORD dwThreadId;
	int noWriters;
	cout << "enter no of writers";
	cin >> noWriters;
	int noReaders;
	cout << "enter no of readers";
	cin >> noReaders;
	for (int i = 0; i < noWriters; i++)
	{
		g_hThreads[g_numThreads++] = CreateThread(NULL, 0, WriterThread, (PVOID)(INT_PTR)i, 0, &dwThreadId);
	}
	for (int i = 0; i < noReaders; i++)
	{
		g_hThreads[g_numThreads++] = CreateThread(NULL, 0, ReaderThread, (PVOID)(INT_PTR)i, 0, &dwThreadId);
	}
	WaitForMultipleObjects(g_numThreads, g_hThreads, TRUE, INFINITE);
	while (g_numThreads--)
		CloseHandle(g_hThreads[g_numThreads]);
	return 1;
}
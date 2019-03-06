#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_THREADS 3
HANDLE g_hEvent;
DWORD WINAPI WordCount(PVOID pvParam)
{
	//WordCount
	//wait till event becomes signaled
	WaitForSingleObject(g_hEvent, INFINITE);
	Sleep(2000);
	printf("Counting Words\n");

	//changes event state to signaled
	//SetEvent(g_hEvent);//other threads won't become scheduled

	//changes event to non-signaled state
	//ResetEvent(g_hEvent);

	return 0;
}

DWORD WINAPI CheckSpellings(PVOID pvParam)
{
	//spellcheck
	//wait till event becomes signaled
	WaitForSingleObject(g_hEvent, INFINITE);
	Sleep(3000);
	printf("Checking Spellings\n");

	//changes event state to signaled
	//SetEvent(g_hEvent);//other threads won't become scheduled

	return 1;
}

DWORD WINAPI GrammarCheck(PVOID pvParam)
{
	//check grammar
	//wait till event becomes signaled
	WaitForSingleObject(g_hEvent, INFINITE);
	Sleep(4000);
	printf("Checking Grammar\n");

	//changes event state to signaled
	//SetEvent(g_hEvent);//other threads won't become scheduled

	return 1;
}

int main(int argc, char *argv[])
{
	//if you create auto-reset event, the system allows 
	//only 1 of 3 threads to become schedulable after SetEvent
	g_hEvent = CreateEvent(NULL,
		TRUE,//FALSE,//manual reset event will be created
		FALSE,//initial state non-signaled
		NULL);

	HANDLE hThread[MAX_THREADS];
	DWORD dwThreadID[MAX_THREADS];

	unsigned int i = 0;

	//spawn all three thread which will access data in read-only

	hThread[i] = CreateThread(NULL, 0, WordCount, NULL, 0, &dwThreadID[i]);
	if (hThread[i] == NULL)
	{
		printf("Unable to create thread %u. Error %d \n,", i, GetLastError());
		return 0;
	}
	i++;

	hThread[i] = CreateThread(NULL, 0, CheckSpellings, NULL, 0, &dwThreadID[i]);
	if (hThread[i] == NULL)
	{
		printf("Unable to create thread %u. Error %d \n,", i, GetLastError());
		return 0;
	}
	i++;

	hThread[i] = CreateThread(NULL, 0, GrammarCheck, NULL, 0, &dwThreadID[i]);
	if (hThread[i] == NULL)
	{
		printf("Unable to create thread %u. Error %d \n,", i, GetLastError());
		return 0;
	}
	printf("Opening the file\n");
	Sleep(5000);

	//changes event state to isgnaled
	SetEvent(g_hEvent);

	//wait till objects become signaled
	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE);

	printf("waiting for the user input before exit\n");
	getchar();
	return 1;

}
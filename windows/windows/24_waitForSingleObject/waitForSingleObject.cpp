#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID  lparam)
{
	Sleep(4000);
	return 1;
}


int main()
{
	DWORD thID1;
	HANDLE hThread1;

	hThread1 = CreateThread(NULL, //thread attributes
		0, //stack size
		thread_func,//start address
		NULL, //parameter
		0,//creation flags
		&thID1);//thread ID
	if (hThread1 == NULL)
	{
		printf("Unable to create a thread\n");
		return 1;
	}

	
	int time;
	cout << "Enter time in milliseconds";
	cin >> time;
	DWORD dw = WaitForSingleObject(hThread1, time);
	//DWORD dw = WaitForSingleObject(hThread1, INFINITE);
	switch (dw)
	{
	case WAIT_OBJECT_0:
		printf("Thread is terminated. The state of the specified object is signaled\n");
		break;
	case WAIT_TIMEOUT:
		printf("Timeout expired and object's state is non signaled\n");
		break;
	case WAIT_FAILED:
		printf("Wait failed\n");
		break;
	}
	CloseHandle(hThread1);
	printf("waiting for user input before exiting the process\n");
	getchar();
	getchar();
	return 0;
}
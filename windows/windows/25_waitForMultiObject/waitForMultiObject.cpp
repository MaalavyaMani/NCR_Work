#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI thread_func1(LPVOID  lparam)
{
	Sleep(5000);
	return 1;
}

DWORD WINAPI thread_func2(LPVOID  lparam)
{
	Sleep(1000);
	return 1;
}


int main()
{
	DWORD thid1, thid2;
	HANDLE hthread1, hthread2;
	HANDLE array_hand[2];

	hthread1 = CreateThread(NULL, //thread attributes
		0, //stack size
		thread_func1,//start address
		NULL, //parameter
		0,//creation flags
		&thid1);//thread ID
	if (hthread1 == NULL)
	{
		printf("Unable to create a thread\n");
		return 1;
	}

	hthread2 = CreateThread(NULL, //thread attributes
		0, //stack size
		thread_func2,//start address
		NULL, //parameter
		0,//creation flags
		&thid2);//thread ID
	if (hthread2 == NULL)
	{
		printf("Unable to create a thread\n");
		return 1;
	}

	array_hand[0] = hthread1;
	array_hand[1] = hthread2;

	//DWORD dw = WaitForMultipleObjects(2, array_hand, TRUE, INFINITE)
	//DWORD dw = WaitForMultipleObjects(2, array_hand, FALSE, INFINITE)

	DWORD dw = WaitForMultipleObjects(2, array_hand, FALSE, 2000);
	switch (dw)
	{
	case WAIT_FAILED:
		printf("wait failed\n");
		break;
	case WAIT_TIMEOUT:
		printf("timeout expired\n");
		break;
	case WAIT_OBJECT_0 + 0:
		printf("thread1 is terminated\n");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("thread 2 is terminated\n");
		break;
	}
	CloseHandle(hthread1);
	CloseHandle(hthread2);

	printf("waiting for user input before exiting process\n");
	getchar();
	return 0;

}
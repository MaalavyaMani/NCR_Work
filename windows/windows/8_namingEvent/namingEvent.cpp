#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<windows.h>
int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("MyEventIsNamed"));
	getchar();
	return 1;
}
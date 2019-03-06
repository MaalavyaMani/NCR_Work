#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stringLen(char *str)
{
	char *s = str;
	while (*s != '\0')
	{
		s++;
	}
	return (s - str);
}

char* stringCat(char* destination, const char*source)
{
	while (*destination != '\0')
	{
		destination++;
	}
	while ((*destination = *source) != '\0')
	{
		destination++;
		source++;
	}

	*destination = '\0';

	return destination;
}

char* stringCopy(char* destination, const char*source)
{
	while (*destination = *source)
	{
		if (*destination == '\0')
			break;
		source++;
		destination++;

	}
	return destination;
}


int stringCmp(char * destination, const char* source)
{
	while (*destination == *source)
	{
		if (*destination == '\0'|| source=='\0')
			break;
		destination++;
		source++;
	}
	
	if (*destination == '\0' || *source == '\0')
		return 1;
	else
		return 0;
}

char* stringRev(char *s)
{
	char *p1, *p2, temp;
	for (p1 = s, p2 = s + stringLen(s) - 1; p1 < p2; p1++, p2--)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	return s;
}


int main()
{
	int ch, res;
	char store[50] = "";
	char *temp;
	char *str1;
	str1 = NULL;

	str1 = (char*)malloc(30 * sizeof(char));
	char *str2;
	str2 = NULL;
	str2 = (char*)malloc(20 * sizeof(char));
	printf("Enter two strings:");
	gets_s(str1, 29);
	gets_s(str2, 19);
	temp = str1;

	printf("Enter an operation to be performed.\n1.stringCopy()\n2.stringCat()\n3.strRev()\n4.stringCmp()\n5.stringLen()");
	scanf_s("%d", &ch);
	
	while (ch <= 5)
	{
		switch (ch)
		{
		case 1:
		{
			stringCopy(store, str2);
			printf("Copied string is :%s\n", store);
			break;
		}
		
		case 2:
		{
			stringCat(str1, str2);
			printf("Concatenated String is: %s\n", str1);
			break;
		}
		
		case 3:
		{
			printf("Reversed string is %s", stringRev(temp));
			break;

		}
		
		case 4:
		{
			res = stringCmp(str1, str2);
			if (res == 1)
				printf("Strings are equal\n");
			else
				printf("Strings are not equal\n");
			break;
		}

		case 5:
		{
			printf("length of first string is %d\n", stringLen(str1));
			printf("length of second string is %d\n", stringLen(str2));
			break;
		}
		
		default:break;
		}
		
		printf("\nChoose another operation to be performed :");
		scanf_s("%d", &ch);
	}
	free(str1);
	free(str2);
	return 0;
}
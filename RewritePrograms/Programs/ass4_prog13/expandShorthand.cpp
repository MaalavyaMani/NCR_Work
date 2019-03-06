#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void expand(char s1[], char s2[]);
int validRange(char c1, char c2);

int main(void)
{
	char str1[500];
	char str2[500];
	printf("Enter a string:");
	gets_s(str1);
	expand(str1, str2);
	printf("%s\n", str2);
	system("pause");
	getchar();
	return EXIT_SUCCESS;
}

void expand(char str1[], char str2[])//To expand the given string
{
	int i, j;
	int dash;
	dash = 0;
	
	for (i = j = 0; str1[i] != '\0'; ++i) {
		if (str1[i] == '-') {
			if (str1[i + 1] == '-')
			{
				printf("Incorrect input");
				exit(0);
			}
			if (i == 0 || str1[i + 1] == '\0') {
				/* '-' is leading or trailing copying it. */
				str2[j++] = str1[i];
			}
			else {
				/* check if this is a valid range. */
				if (validRange(str1[i - 1], str1[i + 1]))
				{
					while (str2[j - 1] < str1[i + 1])
					{
						str2[j] = str2[j - 1] + 1;
						j++;
					}
					/* skip next character we already printed it. */
					++i;
				}
				else {
	
					printf("Not a valid range");
					exit(0);
				}
			}
		}
		else {
			str2[j++] = str1[i];
		}
	}

	str2[j] = '\0';
}

/* validrange:  returns non-zero if c1-c2 is a valid range. */
int validRange(char ch1, char ch2)
{
	if (('a' <= ch1 && ch1 <= 'z') && /* valid range in a-z */
		(ch1 <= ch2 && ch2 <= 'z'))
		return 1;
	if (('A' <= ch1 && ch1 <= 'Z') && /* valid range in A-Z */
		(ch1 <= ch2 && ch2 <= 'Z'))
		return 1;
	if (('0' <= ch1 && ch1 <= '9') && /* valid range in 0-9 */
		(ch1 <= ch2 && ch2 <= '9'))
		return 1;
}
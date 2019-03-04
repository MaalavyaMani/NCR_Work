#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main() {
	int nLeft = 10, nRight = 20;

	int addition = add( nLeft,nRight);
	int subtraction = sub(nLeft,nRight);
	int multiplication = mul(nLeft, nRight);
	int division = divi(nLeft, nRight);
	printf("Addition %d\n Subtraction %d\n Multiplication %d\n Division %d\n",
		addition, subtraction,multiplication,division);
	getchar();

}
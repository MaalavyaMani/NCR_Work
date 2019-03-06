#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include "Header.h"
using namespace std;

int main() {

	int res, operation, nLeft, nRight;
	cout << "enter two numbers";
	cin >> nLeft >> nRight;
	cout << "\nSelect the operation\n 1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n";
	cin >> operation;
	while (operation <= 4 && operation!=0) {
		switch (operation) {
		case 1:
			res = add(nLeft, nRight);
			cout << "Sum of numbers is:" << res << endl;
			break;

		case 2:
			res = sub(nLeft, nRight);
			cout << "Difference of numbers is:" << res << endl;
			break;

		case 3:
			res = mul(nLeft, nRight);
			cout << "Product of numbers is:" << res << endl;
			break;

		case 4:
			res = divi(nLeft, nRight);
			cout << "div of numbers is:" << res << endl;
			break;

		default:
			cout << "Enter a valid input";
			
		}
		cin >> operation;
	}
	getchar();

}
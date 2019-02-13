#include<iostream>
using namespace std;
void main()
{
	
	int x, y, n;
	void swap1(int, int);
	void swap2(int*x, int*y);
	cout << "enter two value\n";
	cin >> x >> y;
	cout << "\nfor CALL BY VALUE press1";
	cout << "\nfor CALL BY REFERENCE press2\n";
	cin >> n;
	switch (n)
	{
	case 1:

		cout << "\nCALL BY VALUE";
		swap1(x, y);
		cout << "\nafter swap";
		break;
	case 2:
		cout << "\nCALL BY REFERENCE";
		swap2(&x, &y);
		break;
	}
}
void swap1(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	cout << "\nswapped values" << x << " " << y;
}
void swap2(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	cout << "\nswapped value" << *x << " " << *y;
}

#include<iostream>
using namespace std;
void main()
{
	int i, j, n, k, temp;
	int a[20];
	cout << "Enter number of elements in an array: ";
	cin >> n;
	cout << "Enter array elements:  ";
	for (k = 0; k < n; k++)
	{
		cin >> a[k];
	}
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	cout << "Sorted array: ";
	for (k = 0; k < n; k++)
		cout << a[k] << " ";

}
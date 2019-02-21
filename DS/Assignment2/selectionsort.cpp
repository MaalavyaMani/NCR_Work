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
	for (i = 0; i < n - 1; i++)
	{
		int loc = i, j = i + 1;
		while (j <= n - 1)
		{
			if (a[j] < a[loc])
			{
				loc = j;
				j++;
			}

			else
				j++;
		}
		swap(a[i], a[loc]);
	}
	cout << "Sorted array: ";
	for (k = 0; k < n; k++)
		cout << a[k] << " ";
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
#include<iostream>
using namespace std;
class sort
{
public:
	int a[20], n, low, high;

	sort()
	{
		low = 0;
		high = 0;
	}
	void input()
	{
		cout << "enter size: ";
		cin >> n;
		cout << endl;
		low = 0;
		high = n - 1;
		cout << "enter " << n << "elements ";
		for (int p = 0; p < n; p++)
		{
			cin >> a[p];
		}
	}

	void quick_sort(int low, int high)
	{
		int pivot = a[low];
		int i, j;
		i = low + 1;
		j = high;
		if (low < high)
		{
			while (1)
			{
				while (i <= high && a[i] < pivot)
					i++;
				while (a[j] > pivot)
					j--;
				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}
			swap(a[low], a[j]);
			quick_sort(low, j - 1);
			quick_sort(j + 1, high);
		}
	}
	void display()
	{
		cout << "elements are";
		for (int p = 0; p < n; p++)
		{
			cout << a[p] << " ";
		}
	}

	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
};

void main()
{
	sort s;
	s.input();
	s.quick_sort(s.low, s.high);
	s.display();
}

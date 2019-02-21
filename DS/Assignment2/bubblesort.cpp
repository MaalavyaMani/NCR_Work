#include<iostream>
using namespace std;

/*void swap(int, int);
void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}*/

void main() {
	int n, i, j, flag=0,k1,temp;
	cout << "enter size";
	cin >> n;
	int a[50];
	for (k1 = 0; k1 < n; k1++)
	{
		cin >> a[k1];
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
			
		}
		if (flag == 0)
			break;
	}
	for (int k = 0; k < n; k++)
		cout << a[k]<<endl;
	
}

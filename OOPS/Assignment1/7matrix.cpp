#include<iostream>
using namespace std;
class Matrix
{
	int a[2][2];
public:
	void getvalues()
	{
		cout << "Enter matrix values:";
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{

				cin >> a[i][j];
			}
		}
	}

	friend void mul(Matrix, Matrix);
};
void mul(Matrix m1, Matrix m2)
{
	int i, j, c[2][2], k;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < 2; k++)

			{
				c[i][j] += m1.a[i][k] * m2.a[k][j];

			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Matrix a, b;
	a.getvalues();
	b.getvalues();
	mul(a, b);
}
#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
public:
	float d1, d2;
	void get_distance()
	{
		cout << "Enter distance in meters:";
		cin >> d1;
		cout << "Enter distance in centimeters:";
		cin >> d2;
	}
	void convert1()
	{
		d1 = d1 * 3.281;
		d2 = d2 * 0.393;
	}
	void display()
	{
		cout << "Feets:" << d1 << " Inches:" << d2;
	}
	friend void add(Distance1, Distance2);
};
class Distance2
{
	float l1, l2;
public:
	void get_distance()
	{
		cout << "Enter distance in feets:";
		cin >> l1;
		cout << "Enter distance in inches:";
		cin >> l2;
	}
	void convert2()
	{
		l1 = l1 * 0.3048;
		l2 = l2 * 2.54;
	}
	void display()
	{
		cout << "Merters:" << l1 << " Centimeters:" << l2;
	}
	friend void add(Distance1, Distance2);
};
void add(Distance1 p, Distance2 q)
{
	p.convert1();
	q.l1 = p.d1 + q.l1;
	q.l2 = p.d2 + q.l2;
	cout << "The result is:" << q.l1 << " " << q.l2;
}
int main()
{
	Distance1 a;
	Distance2 b;
	a.get_distance();
	b.get_distance();
	add(a, b);
}
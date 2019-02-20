#include<iostream>
using namespace std;

class polar {
	float angle, radius;
	static int count;

public:
	polar()
	{
		angle = 0;
		radius = 0;
		count++;
	}
	polar(float a, float b) {

		angle = a;
		radius = b;
		count++;
	}
	polar(polar &s) {

		angle = s.angle;
		radius = s.radius;
		count++;
	}
	void display() {
		cout << count;
	}

};

int polar::count;

void main() {
	polar p1, p2(10, 5), p3(p2);
	p1.display();
	
}
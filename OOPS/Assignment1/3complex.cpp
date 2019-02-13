#include<iostream>
using namespace std;
class complex {
	float real, img;
public:
	complex() {
		real = img = 0;

	}
	complex(float r) {
		real = img = r;
	}
	complex(float r, float i) {
		real = r;
		img = i;
	}
	void add_complex(complex &c1, complex &c2) { 
		real = c1.real + c2. real;
		img = c1.img + c2.img;
			cout << "sum =" << real <<"+i"<< img << endl;
	}
	void mul_complex(complex &c1, complex &c2) {
		real = c1.real*c2.real - c1.img*c2.img;
		real = c1.real*c2.real + c1.img*c2.img;
		cout << "mul =" << real << "+i" << img << endl;
	}

};
int main() {
	complex c1,c2(3),c3(3,4);
	c1.add_complex(c2,c3);
	c1.mul_complex(c2,c3);
	return 0;

}
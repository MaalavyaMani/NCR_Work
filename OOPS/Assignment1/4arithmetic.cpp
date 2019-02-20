#include<iostream>
using namespace std;

inline int add(int x, int y) {
	return(x + y);
}
inline int sub(int x, int y) {
	return(x - y);
}
inline int mul(int x, int y) {
	return(x*y);
}
inline int divi(int x, int y) {
	return(x/y);
}
inline int mod(int x, int y) {
	return(x % y);
}

void main() {
	int x, y;
	cout << "Enter the values";
	cin >> x  >> y;
	cout << "\n add=" << add(x, y);
	cout << "\n sub=" << sub(x, y);
	cout << "\n mul=" << mul(x, y);
	cout << "\n divi=" << divi(x, y);
	cout << "\n mod=" << mod(x, y);
}
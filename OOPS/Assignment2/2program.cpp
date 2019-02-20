#include<iostream>
using namespace std;

class student {
	int rollno;
	char *name;
	int sub1, sub2, sub3;
	int total;
	float avg;
	char grade;
public:
	void cal_avg() {
		total = (sub1 + sub2 + sub3);
	avg = (float)(total) / 3;
	if (avg > 60)
		grade = 'A';
	else 
		if (avg < 60 && avg>50)
		grade = 'B';
	else
		if (avg < 50 && avg>40)
		grade = 'C';
	else
		grade = 'F';
	}
	friend istream& operator>>(istream& cin, student &s1);
	friend ostream& operator<<(ostream& cout, student s1);
};


	istream& operator >> (istream& cin, student &s1) {
		cin >> s1.rollno;
		cin >> s1.name;
		cin >> s1.sub1 >> s1.sub2 >> s1.sub3;
		s1.cal_avg();
		return(cin);
	}

	ostream& operator <<(ostream& cout, student s1) {
		cout << "student roll number"<< s1.rollno <<endl;
		cout << "student name"<<s1.name<<endl;
		cout << "sub1" << s1.sub1 << endl;
		cout << "sub2" << s1.sub2 << endl;
		cout << "sub3" << s1.sub3 << endl;
		cout << "total" << s1.total << endl;
		cout << "average" << s1.avg << endl;
		cout << "grade" << s1.grade << endl;
		return(cout);
	}
	
void main() {
	student s;
	cin >> s;
	cout << s;
	cout << endl;

}
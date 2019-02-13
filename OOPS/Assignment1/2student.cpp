#include<iostream>
using namespace std;
class student {
public:
	char* studentName;
	char grade;
	int maths;
	int science;
	int social;

};
class CollegeCourse{
	student s1;
	float avg;
public:
	void set_Data(const char* sName, char grade, int maths, int science, int social) {
		int len = strlen(sName);
		s1.studentName = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(s1.studentName, sName);
		s1.grade = grade;
		s1.maths = maths;
		s1.science = science;
		s1.social = social;
	}
	void calculateAverage() {
		avg = (s1.maths + s1.science + s1.social) / 3;
		cout << avg << endl;

	}
	void ComputeGrade() {
		
		if (avg > 60) {
			s1.grade = 'A';
			cout << "First Class" << endl;
		}
		
		else if (avg < 60 && avg>50) {
			s1.grade = 'B';
			cout << "Second Class" << endl;
		}
		else if (avg < 50 && avg>40) {
			s1.grade = 'C';
			cout << "Third Class" << endl;
		}
		else if (avg < 40) {
			s1.grade = 'D';
			cout << "Fail" << endl;
		}

	}

	void display() {

		cout << s1.studentName<<" "<<s1.grade<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.social<< endl;
	}
};
int main() {
	CollegeCourse c1;
	c1.set_Data("Maalavya",'D',40, 50, 60);
	c1.calculateAverage();
	c1.ComputeGrade();
	c1.display();
}
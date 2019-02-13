#include<iostream>
using namespace std;
class Time {
	int hours, minutes, seconds;
public:

	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display() {
		cout << "the current time is" << hours << ':' << minutes << ':' << seconds;
	}
	void add_time(Time &t1, Time &t2) {
		hours = t1.hours + t2.hours;
		minutes = t1.minutes + t2.minutes;
		seconds = t1.seconds + t2.seconds;
		
		if (seconds > 60) {
			seconds = seconds - 60;
			minutes = minutes + 1;
		}
		if (minutes > 60) {
			minutes = minutes - 60;
			hours = hours + 1;
		}
		if (hours > 23) {
			hours = 0;
		}

	}
};
int main() {
	Time t1(10, 20, 30), t2(40, 50, 60),t3;
	t1.display();
	t2.display();
	t3.add_time(t1, t2);
	t3.display();
	return 0;
}


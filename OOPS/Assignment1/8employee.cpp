#include<iostream>
using namespace std;

class employee {
	char *name;
	int emp_id;
	int len;
public:
	employee() {
		name = NULL;
		len = 0;
		emp_id = 0;
		cout << name << " " << emp_id;
	}
	employee(const char *s, int id) {
		len = strlen(s);
		name = (char*)malloc((sizeof(char))*(len + 1));
		strcpy(name, s);
		emp_id = id;
		cout << name << " " << emp_id;
	}
	employee(const employee &temp) {
		len = temp.len;
		name = (char*)malloc((sizeof(char))*(len + 1));
		strcpy(name, temp.name);
		emp_id = temp.emp_id;
		cout << name << " " << emp_id;
	}
	~employee()
	{
		cout << "Destructor is called";
			if (name != NULL)
				free(name);
	}
};

void main() {
	employee e1,e2("Maalavya",1122),e3(e2);
}
#include <iostream>
#include <string>

using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

class NamedCircle :public Circle {
	string name;
public:
	NamedCircle(int radius=0, string name="") :Circle(radius) {
		this->name = name;
	}
	void setName_Rad(int radius, string name) {
		this->name = name;
		this->setRadius(radius);
	}
	void show() {
		cout << "�������� " << this->getRadius() << "�� " << this->name;
	}
	string getname() {
		return name;
	}
};

int main() {
	NamedCircle pizza[5];
	string name;
	int radius,max=0,max_i=0;
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">> ";
		cin >> radius >> name;
		pizza[i].setName_Rad(radius, name);
	}
	for (int i = 0; i < 5; i++) {
		if (pizza[i].getArea() > max) {
			max_i = i;
			max = pizza[i].getArea();
		}
	}
	cout << "���� ������ ū ���ڴ� " << pizza[max_i].getname() << "�Դϴ�.";
}
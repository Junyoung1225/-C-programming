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
		cout << "반지름이 " << this->getRadius() << "인 " << this->name;
	}
	string getname() {
		return name;
	}
};

int main() {
	NamedCircle pizza[5];
	string name;
	int radius,max=0,max_i=0;
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
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
	cout << "가장 면적이 큰 피자는 " << pizza[max_i].getname() << "입니다.";
}
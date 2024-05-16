#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

int main() {
	vector<Circle*> v;
	vector<Circle*>::iterator it;
	cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�." << endl;
	int flag, radius;
	string name;
	while (1) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
			cin >> radius >> name;
			v.push_back(new Circle(radius, name));
			break;
		case(2):
			cout << "�����ϰ��� �ϴ� ���� �̸��� >>";
			cin >> name;
			it = v.begin();
			while(it != v.end()) {
				Circle* temp = *it;
				if (temp->getName() == name) {
					it = v.erase(it);
				}
				else {
					it++;
				}
			}
			break;
		case(3):
			for (int i = 0; i < v.size(); i++) {
				cout << v[i]->getName() << endl;
			}
			cout << endl;
			break;
		case(4):
			exit(0);
		default:
			exit(0);
		}
	}
}
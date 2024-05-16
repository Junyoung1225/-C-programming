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
	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
	int flag, radius;
	string name;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> radius >> name;
			v.push_back(new Circle(radius, name));
			break;
		case(2):
			cout << "삭제하고자 하는 원의 이름은 >>";
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
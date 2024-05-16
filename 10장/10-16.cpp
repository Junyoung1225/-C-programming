#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() {
		draw();
	}
};

class Circle:public Shape {
protected:
	void draw() {
		cout << "Circle" << endl;
	}
};
class Rect :public Shape {
protected:
	void draw() {
		cout << "Rectangle" << endl;
	}
};
class Line :public Shape {
protected:
	void draw() {
		cout << "Line" << endl;
	}
};

int main() {
	vector<Shape*> v;
	vector<Shape*>::iterator it;
	int flag;
	cout << "�׷��� �������Դϴ�." << endl;
	while (1) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "��:1, ��:2, �簢��:3 >>";
			cin >> flag;
			switch (flag) {
			case(1):
				v.push_back(new Line());
				break;
			case(2):
				v.push_back(new Circle());
				break;
			case(3):
				v.push_back(new Rect());
				break;
			}
			break;
		case(2):
			cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
			cin >> flag;
			if (flag >= v.size()) {
				cout << "�߸����Է�" << endl;
				break;
			}
			it = v.begin();
			it = it + flag;
			it = v.erase(it);
			break;
		case(3):
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();
			}
			break;
		case(4):
			exit(0);
		default:
			exit(0);
		}
	}
}
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
	cout << "그래픽 에디터입니다." << endl;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "선:1, 원:2, 사각형:3 >>";
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
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> flag;
			if (flag >= v.size()) {
				cout << "잘못된입력" << endl;
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
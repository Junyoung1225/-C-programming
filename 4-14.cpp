#include<iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

class Player {
	string name;
public:
	string getname() {
		return name;
	}
	void setname(string name) {
		this->name = name;
	}
};

class GamblingGame {
	int a, b, c;
	int flag;
	Player player[2];
public:
	GamblingGame() {
		flag = 0;
		string name;
		srand((unsigned)time(0));
		cout << "***** 겜블링 게임을 시작합니다 *****" << endl;
		cout << "첫번째 선수 이름>>";
		cin >> name;
		player[0].setname(name);
		cout << "두번째 선수 이름>>";
		cin >> name;
		player[1].setname(name);
		getchar();
	}
	void start() {
		string tmp;
		while (1) {
			flag = flag % 2;
			cout << player[flag].getname() << ":<enter>";
			if (getline(cin,tmp)) {
				a = rand() % 3;
				b = rand() % 3;
				c = rand() % 3;
				cout << "\t\t" << a << "\t" << b << "\t" << c << "\t";
				if (conclusion() == 1) {
					cout << player[flag].getname() << "님의 승리!!!" << endl;
					break;
				}
				else {
					cout << "아쉽군요!" << endl;
				}
			}
			flag++;
		}
	}
	int conclusion() {
		if (a == b &&a== c) {
			return 1;
		}
		else {
			0;
		}
	}
};

int main() {
	GamblingGame st;
	st.start();
}
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
		cout << "***** �׺��� ������ �����մϴ� *****" << endl;
		cout << "ù��° ���� �̸�>>";
		cin >> name;
		p[0].setname(name);
		cout << "�ι�° ���� �̸�>>";
		cin >> name;
		p[1].setname(name);
	}
	start() {
		string tmp;
		while (1) {
			flag = flag % 2;
			cout << player[flag].getname() << ":<enter>" << endl;
			cin >> tmp;
			if (tmp == "\n") {
				a = rand() % 3;
				b = rand() % 3;
				c = rand() % 3;
				cout << "\t\t" << a << "\t" << b << "\t" << c << "\t";
				if (conclusion() == 1) {
					cout << player[flag].getname() << "���� �¸�!!!" << endl;
					break;
				}
				else {
					cout << "�ƽ�����!" << endl;
				}
			}
			flag++;
		}
	}
	int conclusion() {
		if (a == b == c) {
			return 1;
		}
		else {
			0;
		}
	}
};

claqd
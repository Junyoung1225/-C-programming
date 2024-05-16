#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

int main() {
	map<string, int> student;
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
	int flag = 0, score;
	string name;
	while (1) {
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "이름과 점수>> ";
			cin >> name >> score;
			student[name] = score;
			break;
		case(2):
			cout << "이름>> ";
			cin >> name;
			if (student.find(name) == student.end()) {
				cout << "없음" << endl;
				break;
			}
			cout << name << "의 점수는 " << student.at(name) << endl;
			break;
		case(3):
			cout << "프로그램을 종료합니다...";
			exit(0);
		default:
			exit(0);
		}
	}
}
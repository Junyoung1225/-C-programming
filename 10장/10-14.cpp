#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

int main() {
	map<string, string> password;

	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;
	int flag = 0;
	string name, pass;
	while (1) {
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "이름 암호>>";
			cin >> name >> pass;
			password[name] = pass;
			break;
		case(2):
			cout << "이름?";
			cin >> name;
			if (password.find(name) == password.end()) {
				cout << "없음" << endl;
				break;
			}
			while (1) {
				cout << "암호?";
				cin >> pass;
				if (pass == password.at(name)) {
					cout << "통과!!" << endl;
					break;
				}
				else {
					cout << "실패~~" << endl;
					continue;
				}
			}
			break;
		case(3):
			cout << "프로그램을 종료합니다...";
			exit(0);
		default:
			exit(0);
		}
	}
}
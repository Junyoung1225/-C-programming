#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

int main() {
	map<string, string> password;

	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****" << endl;
	int flag = 0;
	string name, pass;
	while (1) {
		cout << "����:1, �˻�:2, ����:3>> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "�̸� ��ȣ>>";
			cin >> name >> pass;
			password[name] = pass;
			break;
		case(2):
			cout << "�̸�?";
			cin >> name;
			if (password.find(name) == password.end()) {
				cout << "����" << endl;
				break;
			}
			while (1) {
				cout << "��ȣ?";
				cin >> pass;
				if (pass == password.at(name)) {
					cout << "���!!" << endl;
					break;
				}
				else {
					cout << "����~~" << endl;
					continue;
				}
			}
			break;
		case(3):
			cout << "���α׷��� �����մϴ�...";
			exit(0);
		default:
			exit(0);
		}
	}
}
#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;

int main() {
	map<string, int> student;
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << endl;
	int flag = 0, score;
	string name;
	while (1) {
		cout << "�Է�:1, ��ȸ:2, ����:3 >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "�̸��� ����>> ";
			cin >> name >> score;
			student[name] = score;
			break;
		case(2):
			cout << "�̸�>> ";
			cin >> name;
			if (student.find(name) == student.end()) {
				cout << "����" << endl;
				break;
			}
			cout << name << "�� ������ " << student.at(name) << endl;
			break;
		case(3):
			cout << "���α׷��� �����մϴ�...";
			exit(0);
		default:
			exit(0);
		}
	}
}
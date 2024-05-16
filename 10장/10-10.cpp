#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string n=0, string c=0) {
		nation = n;
		capital = c;
	}
	void set(string n, string c) {
		nation = n;
		capital = c;
	}
	string get_nation() {
		return nation;
	}
	string get_capital() {
		return capital;
	}
};


int main() {
	vector<Nation> v;
	v.push_back(Nation("���ѹα�", "����"));
	v.push_back(Nation("�߱�", "����¡"));
	v.push_back(Nation("����", "���"));
	v.push_back(Nation("�̱�", "�ͽ���"));
	v.push_back(Nation("�븸", "Ÿ�̺���"));
	v.push_back(Nation("ĳ����", "��Ÿ��"));
	v.push_back(Nation("������", "���׹�"));
	v.push_back(Nation("������", "�ĸ�"));
	v.push_back(Nation("����Ʈ", "ī�̷�"));
	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;
	int flag = 0;
	string nat,cap;
	while (1) {
		cout << "���� �Է�: 1, ����: 2, ����: 3 >>";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
			cout << "����� ������ �Է��ϼ���(no no �̸� �Է� ��" << endl;
			while (1) {
				flag = 0;
				cout << v.size() + 1 << ">>";
				cin >> nat >> cap;
				if (nat == "no" && cap == "no") {
					break;
				}
				for (int i = 0; i < v.size(); i++) {
					if (nat == v[i].get_nation() && cap == v[i].get_capital()) {
						cout << "already exists !!" << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					v.push_back(Nation(nat, cap));
				}
			}
			break;
		case(2):
			while (1) {
				int random = rand() % v.size();
				cout << v[random].get_nation() << "�� ������?";
				cin >> cap;
				if (cap == "exit") {
					break;
				}
				if (v[random].get_capital() == cap) {
					cout << "Correct !!" << endl;
				}
				else {
					cout << "NO !!" << endl;
				}
			}
			break;
		case(3):
			exit(0);
		default:
			break;
		}
	}
}
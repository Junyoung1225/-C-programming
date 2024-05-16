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
	v.push_back(Nation("대한민국", "서울"));
	v.push_back(Nation("중국", "베이징"));
	v.push_back(Nation("북한", "평양"));
	v.push_back(Nation("미국", "와싱턴"));
	v.push_back(Nation("대만", "타이베이"));
	v.push_back(Nation("캐나다", "오타와"));
	v.push_back(Nation("스위스", "제네바"));
	v.push_back(Nation("프랑스", "파리"));
	v.push_back(Nation("이집트", "카이로"));
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	int flag = 0;
	string nat,cap;
	while (1) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요(no no 이면 입력 끝" << endl;
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
				cout << v[random].get_nation() << "의 수도는?";
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
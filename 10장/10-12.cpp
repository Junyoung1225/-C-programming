#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

class voca{
	string eng;
	string kor;
public:
	voca(string eng, string kor) {
		this->eng = eng;
		this->kor = kor;
	}
	string get_eng() {
		return eng;
	}
	string get_kor() {
		return kor;
	}
};

int main() {
	srand((unsigned)time(0));
	vector<voca> v;
	v.push_back(voca("honey", "����"));
	v.push_back(voca("doll", "����"));
	v.push_back(voca("painting", "�׸�"));
	v.push_back(voca("stock", "�ֽ�"));

	int flag;
	string kor, eng;
	while (1) {
		cout << "���� ����: 1, ���� �׽�Ʈ : 2, ���α׷� ����:�׿�Ű >> ";
		cin >> flag;
		switch (flag) {
		case(1):
			cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
			while (1) {
				cout << "���� >>";
				cin >> eng;
				if (eng == "exit") {
					break;
				}
				cout << "�ѱ� >>";
				cin >> kor;
				v.push_back(voca(eng, kor));
			}
			break;
		case(2):
			cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4�� �ٸ� �Է½� ����." << endl;
			while (1) {
				int random = rand() % v.size();
				cout << v[random].get_eng() << "?" << endl;
				string answer[4] = {"---","---","---","---"};
				int tmp = rand() % 4;
				answer[tmp] = v[random].get_kor();
				int ans_num = 0;
				while (1) {
					if (answer[0] != "---" && answer[1] != "---" && answer[2] != "---" && answer[3] != "---") {
						break;
					}
					if (ans_num == tmp) {
						ans_num++;
						continue;
					}
					random = rand() % v.size();
					int k = 0;
					for (int i = 0; i < 4; i++) {
						if (v[random].get_kor() == answer[i]) {
							k = 1;
							break;
						}
					}
					if (k == 1) {
						continue;
					}
					else {
						answer[ans_num++] = v[random].get_kor();
					}
				}
				cout << "(1) " << answer[0] << " (2) " << answer[1] << " (3) " << answer[2] << " (4) " << answer[3] << " :>";
				cin >> flag;
				if (flag < 1 || flag>4) {
					break;
				}
				if (answer[flag - 1] == answer[tmp]) {
					cout << "Excellent !!" << endl;
				}
				else {
					cout << "NO !!" << endl;
				}
			}
			break;
		default:
			exit(0);
		}
	}
}
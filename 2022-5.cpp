#include<iostream>
#include<string>
#include<vector>
using namespace std;

static class CBoard {
public:
	static string v[20];
	static int cn;
	CBoard() {}
	static void add(string x) {
		v[cn++] = x;
	}
	static void print() {
		cout << "**** �Խ����Դϴ�. ****" << endl;
		for (int i = 0; i < cn; i++) {
			cout << v[i] << endl;
		}
	}
};
int CBoard::cn=0;
string CBoard::v[20];
int main() {
	CBoard::add("�߰���� �ǽ� ��");
	CBoard::add("�� 5����");
	CBoard::print();
	CBoard::add("���������� ���� ���ô�");
	CBoard::print();
	return 0;
}
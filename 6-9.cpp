#include<iostream>
#include<string>
using namespace std;

class Board {
public:
	static string text[100];
	static int count;
	static void add(string con);
	static void print();
};
int Board::count = 0;
string Board::text[100];
void Board::add(string con) {
	Board::text[Board::count++] = con;
}
void Board::print() {
	cout << "***************�Խ����Դϴ�.**************" << endl;
	for (int i = 0; i < count; i++) {
		cout << i << ": " << text[i] << endl;
	}
}

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}
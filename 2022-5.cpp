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
		cout << "**** 게시판입니다. ****" << endl;
		for (int i = 0; i < cn; i++) {
			cout << v[i] << endl;
		}
	}
};
int CBoard::cn=0;
string CBoard::v[20];
int main() {
	CBoard::add("중간고사 실시 중");
	CBoard::add("총 5문제");
	CBoard::print();
	CBoard::add("부정행위를 하지 맙시다");
	CBoard::print();
	return 0;
}
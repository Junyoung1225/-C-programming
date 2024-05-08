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
	cout << "***************게시판입니다.**************" << endl;
	for (int i = 0; i < count; i++) {
		cout << i << ": " << text[i] << endl;
	}
}

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}
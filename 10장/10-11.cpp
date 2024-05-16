#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Book {
	int year;
	string name;
	string author;
public:
	Book(int year = 0, string name = 0, string author = 0) {
		this->year = year;
		this->name = name;
		this->author = author;
	}
	int get_year() {
		return year;
	}
	string get_name() {
		return name;
	}
	string get_author() {
		return author;
	}
};

int main() {
	vector<Book> v;
	int year;
	string name, author;
	while (1) {
		cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
		cout << "년도>>";
		cin >> year;
		if (year == -1) {
			break;
		}
		getchar();
		cout << "책이름>>";
		getline(cin, name);
		cout << "저자>>";
		getline(cin, author);
		v.push_back(Book(year, name, author));
	}
	cout << "총 입고된 책은 " << v.size() << "권입니다.";
	cout << "검색하고자 하는 저자 이름을 입력하세요>>";
	getchar();
	getline(cin, author);
	vector<Book>::iterator p;
	for (p = v.begin(); p != v.end(); p++) {
		if (p->get_author() == author) {
			cout << p->get_year() << "년도, " << p->get_name() << ", " << p->get_author() << endl;
		}
	}
	cout << "검색하고자 하는 년도를 입력하세요>>";
	cin >> year;
	for (p = v.begin(); p != v.end(); p++) {
		if (p->get_year() == year) {
			cout << p->get_year() << "년도, " << p->get_name() << ", " << p->get_author() << endl;
		}
	}
}
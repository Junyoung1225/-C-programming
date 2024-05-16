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
		cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl;
		cout << "�⵵>>";
		cin >> year;
		if (year == -1) {
			break;
		}
		getchar();
		cout << "å�̸�>>";
		getline(cin, name);
		cout << "����>>";
		getline(cin, author);
		v.push_back(Book(year, name, author));
	}
	cout << "�� �԰�� å�� " << v.size() << "���Դϴ�.";
	cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>>";
	getchar();
	getline(cin, author);
	vector<Book>::iterator p;
	for (p = v.begin(); p != v.end(); p++) {
		if (p->get_author() == author) {
			cout << p->get_year() << "�⵵, " << p->get_name() << ", " << p->get_author() << endl;
		}
	}
	cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
	cin >> year;
	for (p = v.begin(); p != v.end(); p++) {
		if (p->get_year() == year) {
			cout << p->get_year() << "�⵵, " << p->get_name() << ", " << p->get_author() << endl;
		}
	}
}
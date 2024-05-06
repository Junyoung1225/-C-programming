#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<cstdlib>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price) {
		this->title = title;
		this->price = price;
	}
	~Book() {
	}
	Book(const Book& x) {
		this->title = x.title;
		this->price = x.price;
	}
	void set(string title, int price) {
		this->title = title;
		this->price = price;
	}
	void show() {
		cout << title << ' ' << price << "원" << endl;
	}
};

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}
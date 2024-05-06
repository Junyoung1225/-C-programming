#include<iostream>
#include <string>

using namespace std;


class buffer {
	string text;
public:
	buffer(string text) {
		this->text = text;
	}
	void add(string text) {
		this->text +=text;
	}
	void print() {
		cout << text << endl;
	}
};

buffer& append(buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	buffer buf("Hello");
	buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
}
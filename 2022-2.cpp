#include<iostream>
#include<string>
using namespace std;

class CBox {
	int x;
	int y;
	char ch;
public:
	CBox(int x=0, int y=0,char ch='*') {
		this->x = x;
		this->y = y;
		this->ch = ch;
	}
	void draw() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << ch;
			}
			cout << endl;
		}
		cout << endl;
	}
	void setSize(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setFill(char ch) {
		this->ch = ch;
	}
};

int main() {
	CBox b(10, 2);
	b.draw();
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();
	return 0;
}
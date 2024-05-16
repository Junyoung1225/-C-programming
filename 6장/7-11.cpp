#include <iostream>
#include <string>

using namespace std;

class Stack {
	int x[100];
	int top;
public:
	Stack() {
		top = -1;
	}
	Stack& operator <<(int x) {
		top++;
		this->x[top] = x;
		return *this;
	}
	bool operator!() {
		if (top < 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void operator >>(int& x) {
		x = this->x[top];
		top--;
	}
};



int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}
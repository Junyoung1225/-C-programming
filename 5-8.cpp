#include<iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack() {
		p = new int[0];
		this->size = 0;
		tos = -1;
	}
	MyIntStack(int size) {
		p = new int[size];
		this->size = size;
		tos = -1;
	}
	MyIntStack(const MyIntStack& s) {
		this->p = new int[s.size];
		this->size = s.size;
		for (int i = 0; i < s.size; i++) {
			this->p[i] = s.p[i];
		}
		this->tos = s.tos;
	}
	~MyIntStack() {
		delete[] p;
	}
	bool push(int n) {
		tos++;
		if (tos < size) {
			p[tos] = n;
			return true;
		}
		else {
			tos--;
			return false;
		}
	}
	bool pop(int& n) {
		if (tos >= 0) {
			n = p[tos];
			tos--;
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}
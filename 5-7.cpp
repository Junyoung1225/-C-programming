#include<iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack() {
		tos = -1;
	}
	bool push(int n) {
		tos++;
		if (tos < 10) {
			p[tos] = n;
			return true;
		}
		else {
			tos--;
			return false;
		}
	}
	bool pop(int& n) {
		if (tos < 0) {
			return false;
		}
		else {
			n = p[tos];
			tos--;
			return true;
		}
	}
};
int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) {
			cout << i  << ' ';
		}
		else {
			cout << endl << i + 1 << " 번째 stack full" << endl;
		}
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) {
			cout << n << ' ';
		}
		else {
			cout << endl << i + 1 << " 번째 stack empty";
		}
	}
	cout << endl;
}
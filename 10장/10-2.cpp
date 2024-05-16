#include <iostream>
#include<string>
using namespace std;

template<class T, class J>
bool equalArrays(T x[], T y[], J num) {
	for (J i = 0; i < num; i++) {
		if (x[i] != y[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5)) {
		cout << "같다";
	}
	else {
		cout << "다르다";
	}
}
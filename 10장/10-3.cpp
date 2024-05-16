#include <iostream>
#include<string>
using namespace std;

template<class T,class J>
void reverseArray(T x[], J num) {
	for (J i = 0; i <= num / 2; i++) {
		int tmp = x[i];
		x[i] = x[num - i-1];
		x[num - 1 - i] = tmp;
	}
}

int main() {
	int x[] = { 1,10,100,5,4};
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) {
		cout << x[i] << ' ';
	}
}
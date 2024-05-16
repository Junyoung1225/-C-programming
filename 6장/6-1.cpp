#include <iostream>
#include <string>
using namespace std;

int add(int x[], int num, int y[]=nullptr) {
	int tot = 0;
	for (int i = 0; i < num; i++) {
		tot += x[i];
	}
	if (y == nullptr) {
		return tot;
	}
	for (int i = 0; i < num; i++) {
		tot += y[i];
	}
	return tot;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}
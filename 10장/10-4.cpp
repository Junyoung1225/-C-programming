#include <iostream>
#include<string>
using namespace std;

template<class T>
bool search(T num, T x[], int cn) {
	for (int i = 0; i < cn; i++) {
		if (num == x[i]) {
			return true;
		}
	}
	return false;
}


int main() {
	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5))
	{
		cout << "100�� �迭 x�� ���ԵǾ� �ִ�";
	}
	else {
		cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�";
	}
}
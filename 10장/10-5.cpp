#include <iostream>
#include<string>
using namespace std;

template<class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	T* x = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++) {
		x[i] = a[i];
	}
	for (int i = 0; i < sizeb; i++) {
		x[i + sizea] = b[i];
	}
	return x;
}

int main() {
	double a[] = { 1,2,3,4,5 };
	double b[] = { 6,7,8,9,10,11 };
	double* x = concat(a,5,b,6);
	for (int i = 0; i < 11; i++) {
		cout << x[i] << ' ';
	}
}
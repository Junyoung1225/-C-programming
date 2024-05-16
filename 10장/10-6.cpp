#include <iostream>
#include<string>

using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* x = new T[sizeSrc];
	retSize = 0;
	int i, j;
	for (i = 0; i < sizeSrc; i++) {
		for (j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				break;
			}
		}
		if (j == sizeMinus) {
			x[retSize++] = src[i];
		}
	}
	return x;
}


int main() {
    int a[] = { 1,2,3,4,5,6,7,8,9,10 };
    int b[] = { 5,6,7,8,9 };
    int size = 0;
    int* p = remove(a, 10, b, 5, size);
    for (int i = 0; i < size; ++i)
        cout << p[i] << ' ';
    cout << endl;
    delete[] p;
    size = 0;
    char c[] = { 'a','b','i','m','c','d','e', };
    char d[] = { 'k','i','m','n','u' };
    char* q = remove(c, 7, d, 5, size);
    for (int i = 0; i < size; ++i)
        cout << q[i] << ' ';
    cout << endl;
    delete[] q;
}
#include <iostream>
#include<string>
using namespace std;

template<class T>
T biggest(T x[], T y) {
	T max=x[0];
	for (T i = 0; i < y; i++) {
		if (max < x[i]) {
			max = x[i];
		}
	}
	return max;
}



int main() {
	int x[] = { 1,10,100,5,2 };
	cout << biggest(x, 5) << endl;
}

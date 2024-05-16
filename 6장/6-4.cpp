#include <iostream>
#include <string>
using namespace std;

class MyVector{
	int* mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() {
		delete[] mem;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << mem[i] << " ";
		}
		cout << endl;
	}
};

MyVector::MyVector(int n=100, int val=0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) {
		mem[i] = val;
	}
}

int main() {
	MyVector x(1, 1), y;
	x.show();
	y.show();
}
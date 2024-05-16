#include <iostream>
#include <string>

using namespace std;
class Matrix {
	int a[4];
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a[0] = a;
		this->a[1] = b;
		this->a[2] = c;
		this->a[3] = d;
	}
	void show() {
		cout << "Matrix = { " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " }" << endl;
	}
	/*
	void operator <<(int y[4]) {
		for (int i = 0; i < 4; i++) {
			this->a[i] = y[i];
		}
	}
	void operator >>(int y[4]) {
		for (int i = 0; i < 4; i++) {
			y[i] = this->a[i];
		}
	}
	*/
	friend void operator <<(Matrix x, int y[4]);
	friend void operator >>(Matrix x, int y[4]);
};
void operator <<(Matrix x, int y[4]) {
	for (int i = 0; i < 4; i++) {
		x.a[i] = y[i];
	}
}
void operator >>(Matrix x, int y[4]) {
	for (int i = 0; i < 4; i++) {
		y[i] = x.a[i];
	}
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) {
		cout << x[i]<<' ';
	}
	cout << endl;
	b.show();
}
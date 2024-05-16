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
	Matrix operator +(Matrix b) {
		Matrix tmp;
		tmp.a[0] = this->a[0] + b.a[0];
		tmp.a[1] = this->a[1] + b.a[1];
		tmp.a[2] = this->a[2] + b.a[2];
		tmp.a[3] = this->a[3] + b.a[3];
		return tmp;
	}
	friend void operator +=(Matrix& a, Matrix& b);
	bool operator ==(Matrix c) {
		if (this->a[0] == c.a[0] && this->a[1] == c.a[1] && this->a[02] == c.a[2] && this->a[3] == c.a[3]) return true;
		else return false;
	}
};
void operator +=(Matrix& x, Matrix& y){
	x.a[0] = x.a[0] + y.a[0];
	x.a[1] = x.a[1] + y.a[1];
	x.a[2] = x.a[2] + y.a[2];
	x.a[3] = x.a[3] + y.a[3];
}


int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) {
		cout << "a and c are the same" << endl;
	}
}
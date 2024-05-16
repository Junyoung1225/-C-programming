#include<iostream>
#include <string>

using namespace::std;

class Color {
	int r, g, b;
public:
	Color() {
		r = 0, g = 0, b = 0;
	}
	Color(int x, int y, int z) {
		r = x; g = y; b = z;
	}
	Color(Color& x) {
		this->r = x.r;
		this->g = x.g;
		this->b = x.b;
	}
	Color operator+(Color y) {
		Color tmp;
		tmp.r = this->r + y.r;
		tmp.g = this->g + y.g;
		tmp.b = this->b + y.b;
		return tmp;
	}
	void show() {
		cout << r << " " << g << " " << b << endl;
	}
	bool operator==(Color y) {
		if (this->r == y.r && this->g == y.g && this->b == y.b) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) {
		cout << "보라색 맞음";
	}
	else {
		cout << "보라색 아님";
	}
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CCircle {
	int radius;
	char fill;
public:
	CCircle(int r) {
		fill = '*';
		radius = r;
	}
	void draw() {
		int k = (2 * radius - 4)/2;
		int count = 0;
		for (int i = 0; i < radius; i++) {
			for (int j = 0; j < k; j++) {
				cout << ' ';
			}
			for (int j = 0; j < 2 * radius - 2 * k; j++) {
				cout << fill;
			}
			k--;
			if (k < 0) {
				k = 0;
				count++;
			}
			cout << endl;
		}
		for (int i = 0; i < radius; i++) {
			for (int j = 0; j < k; j++) {
				cout << ' ';
			}
			for (int j = 0; j < 2 * radius - 2 * k; j++) {
				cout << fill;
			}
			count--;
			if (count <= 0) {
				k++;
			}
			cout << endl;
		}
	}
	void setRadius(int r) {
		this->radius = r;
	}
	void setFill(const char x) {
		this->fill = x;
	}
};
int main() {
	CCircle a(3);
	a.draw();
	a.setRadius(4);
	a.setFill('^');
	a.draw();
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

class SortedArray {
	int size;
	int* p;
	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (p[i] < p[j]) {
					int tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}
	}
public:
	SortedArray() {
		p = nullptr;
		size = 0;
	}
	SortedArray(SortedArray& src) {
		this->size = src.size;
		this->p = new int[this->size];
		for (int i = 0; i < size; i++) {
			this->p[i] = src.p[i];
		}
		this->sort();
	}
	SortedArray(int p[], int size) {
		this->p = new int[size];
		this->size = size;
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
		this->sort();
	}
	~SortedArray() {
		delete[] p;
	}
	SortedArray operator +(SortedArray& op2) {
		SortedArray tmp;
		int i, j;
		tmp.size = this->size + op2.size;
		tmp.p = new int[tmp.size];
		for (i = 0; i < this->size; i++) {
			tmp.p[i] = this->p[i];
		}
		for (j = 0; j < op2.size; j++) {
			tmp.p[i + j] = op2.p[j];
		}
		tmp.sort();
		return tmp;
	}
	SortedArray& operator =(const SortedArray& op2) {
		this->size = op2.size;
		this->p = new int[this->size];
		for (int i = 0; i < size; i++) {
			this->p[i] = op2.p[i];
		}
		return *this;
	}
	void show() {
		cout << "배열 출력 : ";
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}
};
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<cstdlib>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) {
		this->size = dept.size;
		this->scores = new int[dept.size];
		for (int i = 0; i < size; i++) {
			this->scores[i] = dept.scores[i];
		}
	}
	~Dept() {
		delete[] scores;
	}
	int getSize() {
		return size;
	}
	void read() {
		int n;
		for (int i = 0; i < size; i++) {
			cin >> scores[i];
		}
	}
	bool isOver60(int index) {
		if (scores[index] > 60) {
			return true;
		}
		return false;
	}
};

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60 점 이상은 " << n << "명";
}
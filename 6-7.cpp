#include <iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;

class Random {
public:
	static void seed() {
		srand((unsigned)time(0));
	}
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	int r = rand();
	while (1) {
		r = rand();
		if (r >= min && r <= max) {
			return r;
		}
	}
}
char Random::nextAlphabet() {
	char r;
	while (1) {
		r = rand() % 'z';
		if (r >= 'A' && r <= 'Z') {
			return r;
		}
		if (r >= 'a' && r <= 'z') {
			return r;
		}
	}
}
double Random::nextDouble() {
	double a = rand() / 32767.0;
	return a;
}

int main() {
	Random::seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt() << " ";
	}
	cout << endl;
	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << " ";
	}
	cout << endl;
	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << " ";
		if (i == 4) {
			cout << endl;
		}
	}
}
#include <iostream>
#include <string>

using namespace std;

class Statistics {
	int cnt;
	int* p;
public:
	Statistics() {
		p = new int[8];
		cnt = 0;
	}
	Statistics(Statistics& x) {
		this->p = new int[8];
		for (int i = 0; i < 8; i++) {
			this->p[i] = x.p[i];
		}
		this->cnt = x.cnt;
	}
	~Statistics() {
		delete[] p;
	}
	bool operator !() {
		if (cnt==0 && p) {
			return true;
		}
		else {
			return false;
		}
	}

	Statistics& operator <<(int x) {
		p[cnt++] = x;
		return *this;
	}
	void operator ~() {
		for (int i = 0; i < cnt; i++) {
			cout << p[i]<<' ';
		}
		cout << endl;
	}
	void operator >>(int& avg) {
		int total = 0;
		for (int i = 0; i < cnt; i++) {
			total += p[i];
		}
		avg = total / cnt;
	}
};


int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < 5; i++) {
		stat << x[i];
	}
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg= " << avg << endl;
}
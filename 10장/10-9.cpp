#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<int> x;
	int n;
	double tot=0;
	while (1) {
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> n;
		if (n == 0) {
			break;
		}
		tot += n;
		x.push_back(n);
		vector<int>::iterator p;
		for (p = x.begin(); p != x.end(); p++) {
			cout << *p << " ";
		}
		cout << endl << "평균 = " << tot / x.size() << endl;
	}
}
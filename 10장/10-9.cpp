#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<int> x;
	int n;
	double tot=0;
	while (1) {
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
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
		cout << endl << "��� = " << tot / x.size() << endl;
	}
}
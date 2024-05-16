#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	string quest;
	while (1) {
		vector<int> num;
		vector<char> oper;
		cout << "? ";
		getline(cin, quest);
		int flag = 0;
		int cn = 0,k,tot=0;
		for (int i = 0; i < quest.size(); i++) {
			if (quest[i] >= '0' && quest[i] <= '9') {
				if (flag == 1) {
					flag = 0;
					continue;
				}
				num.push_back(quest[i] - '0');
				cn++;
			}
			else if (quest[i] == '*') {
				flag = 1;
				k = num[cn - 1]* (quest[i + 2] - '0');
				num[cn - 1] = k;
			}
			else {
				continue;
			}
		}
		vector<int>::iterator it;
		for (it = num.begin(); it != num.end(); it++) {
			tot += *it;
		}
		cout << quest << " = " << tot << endl;
		cout << endl;
	}
}
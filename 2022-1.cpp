#include<iostream>
#include<string>
using namespace std;

int main() {
	string line,tot;
	cout << "파일의 경로명을 입력하세요." << endl;
	getline(cin, line);
	int flag = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '\\') {
			flag = i;
		}
	}
	flag = flag + 1;
	tot = line.substr(flag,line.size());
	cout << "파일의 이름은 " << tot;
}
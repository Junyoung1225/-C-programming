#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Histogram {
	string x[10];
	int alphabet[26];
	int alphabet_total;
	int cn;
public:
	Histogram(string line) {
		for (int i = 0; i < 26; i++) {
			this->alphabet[i] = 0;
		}
		this->alphabet_total=0;
		this->cn=0;

		x[this->cn++] = line;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				alphabet[line[i] - 'A']++;
				alphabet_total++;
			}
			else if (line[i] >= 'a' && line[i] <= 'z') {
				alphabet[line[i] - 'a']++;
				alphabet_total++;
			}
			else {
				continue;
			}
		}
	}
	void put(string line) {
		x[cn++] = line;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				alphabet[line[i] - 'A']++;
				alphabet_total++;
			}
			else if (line[i] >= 'a' && line[i] <= 'z') {
				alphabet[line[i] - 'a']++;
				alphabet_total++;
			}
			else {
				continue;
			}
		}
	}
	void print() {
		for (int i = 0; i < cn; i++) {
			cout << x[i] << endl;
		}
		cout << endl;
		cout << "ÃÑ ¾ËÆÄºª ±ÛÀÚ¼ö: " << alphabet_total << endl;
		for (int i = 0; i < 26; i++) {
			cout << (char)('a' + i) << "(" << alphabet[i] << ")  :";
			for (int j = 0; j < alphabet[i]; j++) {
				cout << '*';
			}
			cout << endl;
		}
	}
};

int main() {
	Histogram histo("Sejong University");
	histo.put("Software Department");
	histo.put("Midterm programming");
	histo.print();
	return 0;
}
#include <iostream>
#include<string>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};


int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int *s_tot = new int[size*2];
	for (int i = 0; i < size ;i++) {
		s_tot[i] = s1[i];
	}
	for (int i = 0; i < size ; i++) {
		s_tot[size  + i] = s2[i];
	}
	return s_tot;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int flag = 0,cn=0;
	if (retSize == 0) {
		return NULL;
	}
	int* s_rem = new int[retSize];
	for (int i = 0; i < size ; i++) {
		flag = 0;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			s_rem[cn++] = s1[i];
		}
	}
	return s_rem;
}

int main() {
	int x[5], y[5],*tmp;
	cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}
	cout << "��ģ ������ ����Ѵ�" << endl;
	tmp = ArrayUtility2::concat(x, y, 5);
	for (int i = 0; i < 10; i++) {
		cout << tmp[i] << " ";
	}
	cout << endl;
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ 2" << endl;
	int retsize = 2;
	tmp = ArrayUtility2::remove(x, y, 5, retsize);
	for (int i = 0; i < retsize; i++) {
		cout << tmp[i] << " ";
	}
}
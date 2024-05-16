#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyString {
	char* m_data;
	int m_size;
public:
	MyString() {
		m_data = nullptr;
		m_size = 0;
	}
	MyString(const char* input) {
		m_size = 0;
		while (input[m_size] != '\0') {
			m_size++;
		}
		m_data = new char[m_size + 1];
		for (int i = 0; i < m_size; i++) {
			m_data[i] = input[i];
		}
		m_data[m_size] = '\0';
	}
	MyString(const MyString& in) {
		m_size = in.m_size;
		m_data = new char[m_size+1];
		for (int i = 0; i < m_size; i++) {
			m_data[i] = in.m_data[i];
		}
		m_data[m_size] = '\0';
	}
	~MyString() {
		delete[] m_data;
	}
	char& operator[](int pos) {
		return m_data[pos];
	}
	MyString& operator=(const MyString& other) {
		if (this == &other) return *this;
		delete[] m_data;
		m_size = other.m_size;
		m_data = new char[m_size + 1];
		for (int i = 0; i < m_size; i++) {
			m_data[i] = other.m_data[i];
		}
		m_data[m_size] = '\0';
		return *this;
	}
	MyString operator+(MyString& other) {
		int length = m_size + other.m_size;
		char* data = new char[length + 1];
		for (int i = 0; i < m_size; i++) {
			data[i] = m_data[i];
		}
		for (int i = 0; i < other.m_size; i++) {
			data[m_size + i] = other.m_data[i];
		}
		data[length] = '\0';
		return MyString(data);
	}
	friend ostream& operator <<(ostream& os, const MyString& my);
};
ostream& operator<<(ostream& os, const MyString& my) {
	os << my.m_data;
	return os;
}
int main() {
	MyString a("Sejong");
	MyString b = a;
	b[0] = 'C';
	MyString c;
	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
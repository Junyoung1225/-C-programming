#include <iostream>
#include<string>
using namespace std;

class MyString {
    char* str;
    int length;

public:
    // 생성자
    MyString(const char* input) {
        length = 0;
        while (input[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    // 복사 생성자
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // 대입 연산자 오버로딩
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            for (int i = 0; i < length; i++) {
                str[i] = other.str[i];
            }
            str[length] = '\0';
        }
        return *this;
    }

    // 소멸자
    ~MyString() {
        delete[] str;
    }

    // Set 함수
    void Set(const char* input) {
        delete[] str;
        length = 0;
        while (input[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    // += 연산자 오버로딩
    MyString& operator+=(const MyString& other) {
        int new_length = length + other.length;
        char* new_str = new char[new_length + 1];
        for (int i = 0; i < length; i++) {
            new_str[i] = str[i];
        }
        for (int i = 0; i < other.length; i++) {
            new_str[length + i] = other.str[i];
        }
        new_str[new_length] = '\0';

        delete[] str;
        str = new_str;
        length = new_length;
        return *this;
    }

    // + 연산자 오버로딩 (MyString 객체와 문자열 리터럴을 더할 때 사용)
    MyString operator+(const char* input) const {
        int input_length = 0;
        while (input[input_length] != '\0') {
            input_length++;
        }

        int new_length = length + input_length;
        char* new_str = new char[new_length + 1];
        for (int i = 0; i < length; i++) {
            new_str[i] = str[i];
        }
        for (int i = 0; i < input_length; i++) {
            new_str[length + i] = input[i];
        }
        new_str[new_length] = '\0';

        return MyString(new_str);
    }

    // + 연산자 오버로딩 (MyString 객체 간의 더하기 연산)
    MyString operator+(const MyString& other) const {
        int new_length = length + other.length;
        char* new_str = new char[new_length + 1];
        for (int i = 0; i < length; i++) {
            new_str[i] = str[i];
        }
        for (int i = 0; i < other.length; i++) {
            new_str[length + i] = other.str[i];
        }
        new_str[new_length] = '\0';

        return MyString(new_str);
    }

    // << 연산자 오버로딩 (friend 함수로 선언)
    friend ostream& operator<<(ostream& os, const MyString& myStr) {
        os << myStr.str;
        return os;
    }

    // friend 함수를 통한 문자열 리터럴과 MyString 객체의 덧셈 연산자 오버로딩
    friend MyString operator+(const char* lhs, const MyString& rhs) {
        int lhs_length = 0;
        while (lhs[lhs_length] != '\0') {
            lhs_length++;
        }

        int new_length = lhs_length + rhs.length;
        char* new_str = new char[new_length + 1];
        for (int i = 0; i < lhs_length; i++) {
            new_str[i] = lhs[i];
        }
        for (int i = 0; i < rhs.length; i++) {
            new_str[lhs_length + i] = rhs.str[i];
        }
        new_str[new_length] = '\0';

        return MyString(new_str);
    }
};

int main() {
    MyString a("Sejong");
    MyString b = a;

    a.Set("University");
    b += " " + a;

    cout << a << endl;
    cout << b << endl;

    return 0;
}
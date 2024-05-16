#include <iostream>
#include <string>

using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(){
		mem = nullptr;
	}
	BaseMemory(long int size) {
		mem = new char[size];
	}
	void setMemory(char x,int i) {
		mem[i] = x;
	}
	char getMemory(int i) {
		return mem[i];
	}
};

class ROM :public BaseMemory {
	int size;
public:
	ROM(long int size, char* x, int arr) :BaseMemory(size) {
		for (int i = 0; i < arr; i++) {
			setMemory(x[i], i);
		}
		this->size = arr;
	}
	char read(int i) {
		return getMemory(i);
	}
};

class RAM :public BaseMemory {
	int size;
public:
	RAM(long int size) : BaseMemory(size) {
	}
	void write(int i, char x) {
		setMemory(x, i);
	}
	char read(int i) {
		return getMemory(i);
	}
};
int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024*10,x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) {
		mainMemory.write(i, biosROM.read(i));
	}
	for (int i = 0; i < 5; i++) {
		cout << mainMemory.read(i);
	}
}
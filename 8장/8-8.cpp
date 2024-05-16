#include <iostream>
#include <string>

using namespace std;

class printer {
	string model;
	string manufacturer;
	int availableCount;
public:
	printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	void print(int pages) {
		if (this->availableCount < pages) {
			return;
		}
		availableCount -= pages;
	}
	string get_model() {
		return model;
	}
	string get_manufacturer() {
		return manufacturer;
	}
	int get_availableCount() {
		return availableCount;
	}
};

class inkjet :public printer {
	int availableInk;
public:
	inkjet(string model, string manufacturer, int availableCount, int availableInk) :printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void printInkJet(int pages) {
		if (availableInk >= pages && get_availableCount() >= pages) {
			availableInk -= pages;
			print(pages);
			return;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			return;
		}
	}
	void show() {
		cout << get_model() << " ," << get_manufacturer() << " ,남은 종이 " << get_availableCount() << "장 ,남은 잉크 " << availableInk << endl;
	}
};

class lazer : public printer {
	int availableToner;
public:
	lazer(string model, string manufacturer, int availableCount, int availableToner) :printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void printlazer(int pages) {
		if (availableToner >= pages && get_availableCount()>=pages) {
			availableToner -= pages/2;
			print(pages);
			return;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			return;
		}
	}
	int get_availableToner() {
		return availableToner;
	}
	void show() {
		cout << get_model() << " ," << get_manufacturer() << " ,남은 종이 " << get_availableCount() << "장 ,남은 토너 " << get_availableToner() << endl;
	}
};

int main() {
	char flag='y';
	int printer, pages;
	inkjet* ink = new inkjet("Officejet V40","HP",5,10);
	lazer* laz = new lazer("SCX-6x45","삼성전자",3,20);
	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laz->show();
	cout << endl;
	while (flag != 'n') {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> pages;
		if (printer == 1) {
			ink->printInkJet(pages);
		}
		else {
			laz->printlazer(pages);
		}
		ink->show();
		laz->show();
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> flag;
		cout << endl;
	}
	delete ink;
	delete laz;
}
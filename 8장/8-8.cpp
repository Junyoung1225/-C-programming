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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return;
		}
	}
	void show() {
		cout << get_model() << " ," << get_manufacturer() << " ,���� ���� " << get_availableCount() << "�� ,���� ��ũ " << availableInk << endl;
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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return;
		}
	}
	int get_availableToner() {
		return availableToner;
	}
	void show() {
		cout << get_model() << " ," << get_manufacturer() << " ,���� ���� " << get_availableCount() << "�� ,���� ��� " << get_availableToner() << endl;
	}
};

int main() {
	char flag='y';
	int printer, pages;
	inkjet* ink = new inkjet("Officejet V40","HP",5,10);
	lazer* laz = new lazer("SCX-6x45","�Ｚ����",3,20);
	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ink->show();
	cout << "������ : ";
	laz->show();
	cout << endl;
	while (flag != 'n') {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> pages;
		if (printer == 1) {
			ink->printInkJet(pages);
		}
		else {
			laz->printlazer(pages);
		}
		ink->show();
		laz->show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> flag;
		cout << endl;
	}
	delete ink;
	delete laz;
}
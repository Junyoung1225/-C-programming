#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
	string name;
	int money;
public:
	Account(string name, int money) {
		this->name = name;
		this->money = money;
	}
	string get_name() {
		return name;
	}
	int get_money() {
		return money;
	}
	void deposit_money(int money) {
		this->money += money;
	}
	void withdraw_money(int money) {
		this->money -= money;
	}
};

class Bank {
	vector<Account> user;
public:
	void createAccount(Account x) {
		user.push_back(x);
	}
	void deposit(string name, int money) {
		vector<Account>::iterator it;
		for (it = user.begin(); it != user.end(); it++) {
			if (it->get_name() == name) {
				it->deposit_money(money);
				break;
			}
		}
	}
	void withdraw(string name, int money) {
		vector<Account>::iterator it;
		for (it = user.begin(); it != user.end(); it++) {
			if (it->get_name() == name) {
				it->withdraw_money(money);
				break;
			}
		}
	}
	void transfer(string name1, string name2, int money) {
		vector<Account>::iterator it;
		for (it = user.begin(); it != user.end(); it++) {
			if (it->get_name() == name1) {
				it->withdraw_money(money);
				break;
			}
		}
		for (it = user.begin(); it != user.end(); it++) {
			if (it->get_name() == name2) {
				it->deposit_money(money);
				break;
			}
		}
	}
	void print() {
		vector<Account>::iterator it;
		for (it = user.begin(); it != user.end(); it++) {
			cout << "Account name = " << it->get_name() << ", money = " << it->get_money() << endl;
		}
		cout << "--------------------------------- " << endl;
		cout << endl;
	}
};

int main() {
	Bank bank; 
	bank.createAccount(Account("Kim", 3000));
	bank.createAccount(Account("Lee", 2000)); 
	bank.createAccount(Account("Choi", 10000));
	
	bank.deposit("Kim", 1000); 
	bank.withdraw("Lee", 1000); 
	bank.transfer("Choi", "Lee", 5000); 
	bank.print();  

	bank.transfer("Kim", "Choi", 3000); 
	bank.print();
}
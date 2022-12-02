#include <iostream>
#include <string>
using namespace std;

class Customer
{
private: 
	string name, acctNum;
	float balance;
public:
	Customer(string name = "Sam Pell", string acctNum = "0", float balance = 0.0f)
	{
		this->name = name;
		this->acctNum = acctNum;
		this->balance = balance;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setAcctNum(string acctNum)
	{
		this->acctNum = acctNum;
	}
	void setBalance(int balance)
	{
		this->balance = balance;
	}

	string getName() { return name; }
	string getAcctNum() { return acctNum; }
	float getBalance() { return balance; }
	
	void deposit(float amount)
	{
		balance += amount;
	}

	void withdraw(float amount)
	{
		if (amount > getBalance())
			cout << "Insuffiencient funds" << endl;
		else
			balance -= amount;
	}

	void checkBalance()
	{
		cout << name << " has a current balance of " << getBalance() << endl;
	}

};

int main()
{
	Customer user1("Anthony", "001", 100.00);
	user1.checkBalance();
	cout << user1.getAcctNum() << endl;
	cout << user1.getName() << endl;
	cout << user1.getBalance() << endl;

	user1.deposit(200.00);
	user1.checkBalance();

	user1.withdraw(10000);
	user1.withdraw(50);
	user1.checkBalance();

	return 0;
}
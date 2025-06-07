#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount {
private:
	std::string accountHolder;  
	int accountNumber;  
	double balance;  

public:
	BankAccount();
	BankAccount(const std::string &accHolder, int accNum, double initBalance);
	BankAccount(const BankAccount &other);
	BankAccount(std::string&& holder, int number, double initialBalance);
	~BankAccount();

	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;

	std::string getAccountHolder() const;
	int getAccountNumber() const;
	double getBalance() const;

};

#endif

#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : accountHolder("Unknown"), accountNumber(0), balance(0.0) {
	std::cout << "Default account created" << std::endl;
}

BankAccount::BankAccount(const std::string &accHolder, int accNum, double initBalance) : accountHolder(accHolder), accountNumber(accNum), balance(initBalance) {
	std::cout << "Account created for " << accHolder << std::endl;
}

BankAccount::BankAccount(const BankAccount &other) : accountHolder(other.accountHolder), accountNumber(other.accountNumber), balance(other.balance) {
	std::cout << "Account copied for " << accountHolder << std::endl;
}

BankAccount::BankAccount(std::string&& accHolder, int accNum, double initBalance) : accountHolder(std::move(accHolder)), accountNumber(accNum), balance(initBalance) {
	std::cout << "Account created (initializer list) for " << accountHolder << std::endl;
}

BankAccount::~BankAccount() {
	std::cout << "Account destroyed for " << accountHolder << std::endl;
}

void BankAccount::deposit(double amount) {
	if (amount > 0) {
		balance += amount;
		std::cout << "Deposited $" << amount << " to account " << accountNumber << std::endl;
	} else {
		std::cout << "Invalid deposit amount" << std::endl;
	}
}

bool BankAccount::withdraw(double amount) {
	if (amount > 0 && balance >= amount) {
		balance -= amount;
		std::cout << "Withdrew $" << amount << " from account " << accountNumber << std::endl;
		return true;
	}
	std::cout << "Withdrawal failed for account " << accountNumber << std::endl;
	return false;
}

void BankAccount::display() const {
	std::cout << "Account Holder: " << accountHolder 
			  << "\nAccount Number: " << accountNumber 
			  << "\nBalance: $" << balance << std::endl;
}

std::string BankAccount::getAccountHolder() const {
	return accountHolder;
}

int BankAccount::getAccountNumber() const {
	return accountNumber;
}

double BankAccount::getBalance() const {
	return balance;
}

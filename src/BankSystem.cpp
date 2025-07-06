#include "BankSystem.h"
#include <iostream>

void BankSystem::addAccount(const std::string &accHolder, int accNum, double initBalance) {
	for (size_t i = 0; i < accounts.size(); ++i) {
		if (accounts[i].getAccountNumber() == accNum) {
			std::cout << "Account number " << accNum << " already exists." << std::endl;
			return;
		}
	}
	accounts.push_back(accHolder, accNum, initBalance);
}

BankAccount* BankSystem::findAccount(int accNum) {
	for (auto &account : accounts) {
		if (account.getAccountNumber() == accNum) {
			return &account;
		}
	}
	std::cout << "Account " << accNum << " not found." << std::endl;
	return nullptr;
}

void BankSystem::transferFunds(int senderAccNum, int receiverAccNum, double amount) {
	BankAccount* sender = findAccount(senderAccNum);
	BankAccount* receiver = findAccount(receiverAccNum);
	
	if (sender && receiver) {
		if (sender->withdraw(amount)) {
			receiver->deposit(amount);
			std::cout << "Transferred " << amount << "$ from account " << senderAccNum 
					  << " to account " << receiverAccNum << std::endl;
		}
	} else {
		std::cout << "Transfer failed. 0 accounts found." << std::endl;
	}
}

void BankSystem::displayAllAccounts() const {
	std::cout << "\nAll Bank Accounts" << std::endl;
	for (size_t i = 0; i < accounts.size(); ++i) {
		std::cout << "\t";
		accounts[i].display();
	}
}

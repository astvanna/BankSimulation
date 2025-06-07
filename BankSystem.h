#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
#include <vector>
#include "BankAccount.h"

class BankSystem {
private:
	std::vector<BankAccount> accounts;

public:
	void addAccount(const std::string &holderName, int accountNumber, double initialBalance);
	BankAccount* findAccount(int accountNumber);
	void transferFunds(int senderAcc, int receiverAcc, double amount);
	void displayAllAccounts() const;
};

#endif

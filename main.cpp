#include "BankSystem.h"
#include <iostream>

int main() {
    BankSystem bank;

    // Adding accounts
    bank.addAccount("Alice Smith", 1001, 500.0);
    bank.addAccount("John Doe", 1002, 1000.0);

    // Try to add duplicate account
    bank.addAccount("Duplicate", 1001, 200.0);

    // Display all accounts
    bank.displayAllAccounts();

    // Depositing and withdrawing money
    BankAccount* aliceAccount = bank.findAccount(1001);
    if (aliceAccount) {
        aliceAccount->deposit(200);
    }

    BankAccount* johnAccount = bank.findAccount(1002);
    if (johnAccount) {
        johnAccount->withdraw(150);
    }

    // Try to find non-existent account
    bank.findAccount(9999);

    // Transferring funds
    bank.transferFunds(1002, 1001, 300);

    // Try invalid transfer
    bank.transferFunds(1002, 1001, 2000); // Should fail - insufficient funds

    // Display accounts after transactions
    bank.displayAllAccounts();

    return 0;
}

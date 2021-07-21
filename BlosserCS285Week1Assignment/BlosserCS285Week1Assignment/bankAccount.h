#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class bankAccount
{
private:
	string accountName;
	int accountNumber;
	string accountType;
	double accountBalance;
	double interestRate;
	static int assignAccount;

public:
	bankAccount();
	bankAccount(string, string, double, double);
	void deposit(double amount);
	void withdraw(double amount);
	void updateBalance();
	void print();
	void setAccountHolderName(string name);
	void setAccountType(string type);
	void setBalance(double balance);
	void setInterestRate(double rate);
	
	double getInterest() const;
	int getAccountNumber() const;
	string getAccountHolderName() const;
	string getAccountType() const;
	double getBalance() const;
	double getInterestRate() const;
};
#endif


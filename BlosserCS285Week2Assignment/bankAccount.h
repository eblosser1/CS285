#include <iostream>
#include <string>

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class bankAccount
{
protected:
	int accountNumber;
	string accountName;
	double accountBalance;

public:
	bankAccount();
	bankAccount(int acctNum, string acctName, double startBal);
	~bankAccount();
	int getAccountNumber();
	double getBalance();
	string getAccountName();
	string setAccountName(string acctName);
	double deposit(double depositAmount);
	virtual double withdraw(double withdrawAmount);
	virtual void print();
	virtual void createMonthlyStatement() = 0;
};
#endif


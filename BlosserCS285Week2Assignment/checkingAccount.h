#include "bankAccount.h"
#include <iostream>
#include <string>
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

using namespace std;

class checkingAccount : public bankAccount
{
private:
	double interestRate;
	double minimumBalance;
	double serviceCharge;
	double fee;

public:
	checkingAccount();
	checkingAccount(string acctName, int acctNumber, double startBal, double minBalance, double intRate, double srvCharge, double monthFee);
	~checkingAccount();
	double getMinimumBalance();
	void setMinimumBalance(double minBalance);
	double getInterestRate();
	void setInterestRate(double intRate);
	double getServiceCharge();
	void setServiceCharge(double srvCharge);
	double postInterest();
	void writeCheck(int checkAmount);
	double withdraw(double withdrawAmount);
	void print();
	void createMonthlyStatement();
	bool verifyMinimumBalance();
};

#endif

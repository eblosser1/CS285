#include "bankAccount.h"
#include <iostream>
#include <string>

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

using namespace std;

class savingsAccount : public bankAccount
{
private:
	double interestRate;

public:
	savingsAccount();
	savingsAccount(string acctName, int acctNumber, double startBal, double intRate);
	~savingsAccount();
	double getInterestRate();
	void setInterestRate(double intRate);
	double withdraw(double amount);
	double postInterest();
	void print();
	void createMonthlyStatement();
	
};

#endif

#include "savingsAccount.h"
#include "bankAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

savingsAccount::savingsAccount()
{

}

savingsAccount::savingsAccount(string acctName, int acctNumber, double startBal, double intRate)
{
	bankAccount::accountName = acctName;
	bankAccount::accountNumber = acctNumber;
	bankAccount::accountBalance = startBal;
	interestRate = intRate;
}

savingsAccount::~savingsAccount()
{

}

double savingsAccount::getInterestRate()
{
	return interestRate;
}

void savingsAccount::setInterestRate(double intRate)
{
	interestRate = intRate;
}

double savingsAccount::withdraw(double amount)
{
	if ((bankAccount::accountBalance - amount) < 0)
	{
		cout << "*** Insufficient Funds ***" << endl;
	}

	else
	{
		bankAccount::accountBalance -= amount;
	}
	return bankAccount::accountBalance;
}

double savingsAccount::postInterest()
{
	double interest = 0;
	interest = bankAccount::accountBalance * (interestRate / 100);
	bankAccount::accountBalance += interest;
	bankAccount::accountBalance = bankAccount::accountBalance;

	return interest;
}

void savingsAccount::print()
{
	//print Account Number
	cout << "Savings ACCT#: " << getAccountNumber() << endl;
	//print Current Balance
	cout << "Balance: $" << getBalance() << endl;
	//print Interest Rate
	cout << "Interest Rate = " << fixed << setprecision(2) << getInterestRate() * 100<< "%" << endl;
}

void savingsAccount::createMonthlyStatement()
{
	postInterest();
	bankAccount::accountBalance = bankAccount::accountBalance + (bankAccount::accountBalance * getInterestRate());
}


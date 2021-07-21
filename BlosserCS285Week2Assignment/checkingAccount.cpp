#include "checkingAccount.h"
#include "bankAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

checkingAccount::checkingAccount()
{

}

checkingAccount::checkingAccount(string acctName, int acctNumber, double startBal, double minBalance, double intRate, double srvCharge, double monthFee)
{
	bankAccount::accountName = acctName;
	bankAccount::accountNumber = acctNumber;
	bankAccount::accountBalance = startBal;
	minimumBalance = minBalance;
	interestRate = intRate;
	serviceCharge = srvCharge;
	fee = monthFee;
	
}

checkingAccount::~checkingAccount()
{
}

double checkingAccount::getMinimumBalance()
{
	return minimumBalance;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

double checkingAccount::getInterestRate()
{
	return interestRate;
}

void checkingAccount::setInterestRate(double intRate)
{
	interestRate = intRate;
}

double checkingAccount::getServiceCharge()
{
	return serviceCharge;
}

void checkingAccount::setServiceCharge(double srvCharge)
{
	serviceCharge = srvCharge;
}

double checkingAccount::postInterest()
{
	if (bankAccount::accountBalance <= 0)
	{
		return 0;
	}
	double interest = 0;
	interest = bankAccount::accountBalance * (interestRate / 100);
	bankAccount::accountBalance += interest;
	bankAccount::accountBalance = bankAccount::accountBalance;

	return interest;
}

void checkingAccount::writeCheck(int checkAmount)
{
	if ((bankAccount::accountBalance - checkAmount) < 0)
	{
		cout << "***Insufficient Funds ***" << endl;
		return;
	}

	withdraw(checkAmount);

	if (verifyMinimumBalance())
	{
		bankAccount::accountBalance -= getServiceCharge();
		cout << "Warning--Your Account Is Below The Mininmum Balance." << endl;
		cout << "You have been charged a fee of $" << getServiceCharge() << endl;
	}

	cout << "Check Sent For: $" << checkAmount << endl;
	cout << "Your New Balance Is: $" << getBalance() << endl;
}

double checkingAccount::withdraw(double amount)
{
	if ((bankAccount::accountBalance - amount) < 0)
	{
		cout << "*** Insufficient Funds ***" << endl;
	}

	else
	{
		bankAccount::accountBalance -= amount;

		if (verifyMinimumBalance())
		{
			bankAccount::accountBalance -= getServiceCharge();
			cout << "Warning--Your Account Is Below The Mininmum Balance." << endl;
			cout << "You have been charged a fee of $" << getServiceCharge() << endl;
		}
	}

	return bankAccount::accountBalance;
}

void checkingAccount::print()
{
	//print Account Number
	cout << "Interest Checking ACCT#: " << getAccountNumber() << endl;
	//print Current Balance
	cout << "Balance: $" << fixed << setprecision(2) << getBalance() << endl;
	//print Interest Rate
	cout << "Interest Rate = " << fixed << setprecision(2) << getInterestRate() * 100 << "%" << endl;
}

void checkingAccount::createMonthlyStatement()
{
	postInterest();
	bankAccount::accountBalance = bankAccount::accountBalance + (bankAccount::accountBalance * getInterestRate()) - getServiceCharge();
}

bool checkingAccount::verifyMinimumBalance()
{
	bool balanceLow = false;

	if (bankAccount::accountBalance < minimumBalance)
	{
		balanceLow = true;
	}

	return balanceLow;
}






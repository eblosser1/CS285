#include <iostream>
#include <stdio.h>
#include <string.h>
#include "bankAccount.h"

using namespace std;

bankAccount::bankAccount() 
{	
	
}

bankAccount::bankAccount(int acctNum, string acctName, double startBal)
{
	accountNumber = acctNum;
	accountName = acctName;
	accountBalance = startBal;
}

bankAccount::~bankAccount()
{

}

int bankAccount::getAccountNumber()
{
	return accountNumber;
}

double bankAccount::getBalance()
{
	return accountBalance;
}

string bankAccount::getAccountName()
{
	return accountName;
}

string bankAccount::setAccountName(string acctName)
{
	accountName = acctName;
	return accountName;
}

double bankAccount::deposit(double depositAmount)
{
	accountBalance += depositAmount;
	return accountBalance;
}

double bankAccount::withdraw(double withdrawAmount)
{
	accountBalance -= withdrawAmount;
	return accountBalance;
}

void bankAccount::print()
{
	cout << "---------------------------------------" << endl;
	cout << "Account Number: " << getAccountNumber() << endl;
	cout << "Balance: $" << getBalance() << endl;
	cout << "---------------------------------------";
}





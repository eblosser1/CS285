#include <iostream>
#include <stdio.h>
#include <string.h>
#include "bankAccount.h"

using namespace std;

int bankAccount::assignAccount = 10000;

bankAccount::bankAccount()
{
	accountName = "";
	accountType = "";
	accountBalance = 0.0;
	interestRate = 0.0;
	accountNumber = assignAccount;
	assignAccount++;
}

bankAccount::bankAccount(string name, string type, double balance, double rate)
{
	accountName = name;
	accountType = type;
	accountBalance = balance;
	interestRate = rate;
	accountNumber = assignAccount;
	assignAccount++;
}

void bankAccount::deposit(double add)
{
	accountBalance += add;
}

void bankAccount::withdraw(double sub)
{
	accountBalance -= sub;
}

void bankAccount::updateBalance()
{
	accountBalance += getInterest();
}

void bankAccount::print()
{
	cout << "---------------------------------------" << endl;
	cout << "Account Number: " << getAccountNumber() << endl;
	cout << "Account Name: " << getAccountHolderName() << endl;
	cout << "Account Type: " << getAccountType() << endl;
	cout << "Balance: $" << getBalance() << endl;
	cout << "Interest Rate: " << getInterestRate() << "%" << endl;
	cout << "---------------------------------------";
}

void bankAccount::setAccountHolderName(string name)
{
	accountName = name;
}

void bankAccount::setAccountType(string type)
{
	accountType = type;
}

void bankAccount::setBalance(double balance)
{
	accountBalance = balance;
}

void bankAccount::setInterestRate(double rate)
{
	interestRate = rate;
}

double bankAccount::getInterest() const
{
	return accountBalance * interestRate;
}

int bankAccount::getAccountNumber() const
{
	return accountNumber;
}

string bankAccount::getAccountHolderName() const
{
	return accountName;
}

string bankAccount::getAccountType() const
{
	return accountType;
}

double bankAccount::getBalance() const
{
	return accountBalance;
}

double bankAccount::getInterestRate() const
{
	return interestRate;
}

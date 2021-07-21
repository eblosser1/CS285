#include <iostream>
#include <iomanip>
#include "savingsAccount.h"
#include "checkingAccount.h"

using namespace std;

int main()

{
	bankAccount* accountsList[6];

	accountsList[0] = new checkingAccount("Bill", 10200, 25000, 100, 0.012, 10.00, 5.00);
	accountsList[1] = new checkingAccount("Bob", 10210, 10000, 100, 0.0099, 15.00, 5.00);
	accountsList[2] = new savingsAccount("Susan", 90001, 20000, 0.031);
	accountsList[3] = new savingsAccount("Steve", 90002, 50000, 0.041);
	accountsList[4] = new checkingAccount("Sally", 10220, 4999, 100, 0.0079, 20.00, 5.00);
	accountsList[5] = new savingsAccount("Frad", 90003, 2000, 0.011);


	cout << "January:\n-------------" << endl;

	for (int i = 0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
	}

	cout << "\nFebruary:\n-------------" << endl;

	for (int i = 0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
	}

	for (int i = 0; i < 6; i++)
	{
		accountsList[i]->withdraw(500);
	}

	cout << "\nMarch:\n-------------" << endl;

	for (int i = 0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
	}

	return 0;

}
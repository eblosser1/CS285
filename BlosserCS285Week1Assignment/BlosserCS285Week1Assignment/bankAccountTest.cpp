#include <iostream>
#include <string>
#include "bankAccount.h"
#include <time.h>

using namespace std;

int main()
{
	bankAccount account[10];

	bankAccount* member;
	member = new bankAccount("Eric", "Savings", 6543.43, 4.5);
	account[0] = *member;

	member = new bankAccount("Kaitlyn", "Checking", 4352.23, 3.4);
	account[1] = *member;

	member = new bankAccount("David", "Savings", 5034.43, 3.6);
	account[2] = *member;

	member = new bankAccount("Janice", "Checking", 1535.98, 2.4);
	account[3] = *member;

	member = new bankAccount("Megan", "Savings", 454.21, 4.3);
	account[4] = *member;

	member = new bankAccount("Justin", "Checking", 564.90, 3.2);
	account[5] = *member;

	member = new bankAccount("Kelly", "Savings", 1100.00, 4.6);
	account[6] = *member;

	member = new bankAccount("Derek", "Checking", 1222.65, 4.4);
	account[7] = *member;

	member = new bankAccount("Kaden", "Savings", 1632.34, 3.8);
	account[8] = *member;

	member = new bankAccount("Kevin", "Checking", 1403.06, 4.1);
	account[9] = *member;

	for (int i = 0; i < 10; i++)
	{
		account[i].print();
		cout << endl << endl;
	}

	//system ("pause");
	system("pause");

	return 0;
}
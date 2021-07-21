#include <iostream>
#include <string>
#include <iomanip>
#include "fractionType.h"

using namespace std;

int main()
{
	try
	{
		fractionType<int> num1(1, 0);
		fractionType<int> num2(0, 3);
		fractionType<int> num3;

		cout << fixed;
		cout << showpoint;
		cout << setprecision(2);

		num3 = num1 / num2;

		cout << num1 << "/" << num2 << "=" << num3 << endl;
	}

	catch (fractionException e)
	{
		cout << "Exception caught in main: " << e.what() << endl;
	}

	catch (...)
	{

	}

	return 0;
}


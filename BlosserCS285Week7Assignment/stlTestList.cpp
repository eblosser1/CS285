#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#include "linkedList.h"

using namespace std;

int main()
{
	list<int> intList1, intList2, intList3;

	ostream_iterator<int> screen(cout, " ");

	intList1.push_back(23);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(36);
	intList1.push_back(15);
	intList1.push_back(93);
	intList1.push_back(98);
	intList1.push_back(58);

	cout << "Line 22: intList1: ";
	copy(intList1.begin(), intList1.end(), screen);
	cout << endl;

	intList2 = intList1;

	cout << "Line 28: intList2: ";
	copy(intList2.begin(), intList2.end(), screen);
	cout << endl;

	intList1.unique();

	cout << "Line 34: After removing the consecutive duplicates," << endl;
	cout << "intList1: ";
	copy(intList1.begin(), intList1.end(), screen);
	cout << endl;

	intList2.sort();

	cout << "Line 39: After sorting, intList2: ";
	copy(intList2.begin(), intList2.end(), screen);
	cout << endl;

	intList3.push_back(13);
	intList3.push_back(25);
	intList3.push_back(23);
	intList3.push_back(198);
	intList3.push_back(136);

	cout << "Line 49: intList3: ";
	copy(intList3.begin(), intList3.end(), screen);
	cout << endl;

	intList3.sort();

	cout << "Line 55: After sorting, intList3: ";
	copy(intList3.begin(), intList3.end(), screen);
	cout << endl;

	intList2.merge(intList3);

	cout << "Line 63: After merging intList2 and intList3, intList2: " << endl << " ";
	copy(intList2.begin(), intList2.end(), screen);
	cout << endl;

	return 0;
}
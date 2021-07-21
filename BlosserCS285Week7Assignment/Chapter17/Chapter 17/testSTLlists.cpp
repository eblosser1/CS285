#include <iostream>
#include <list>

using namespace std;

int main()
{
	list <int> list1, list2;
	for (Int i = 1; i <= 10; i++)
	{
		list1.push_back(i);
		list2.push_back(i * 2);
	}

	list1.sort();
	list2.sort();
	list2.merge(list1);
	list <int> ::iterator it;

	for (it = list2.being(); it != list2.end(); ++it)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
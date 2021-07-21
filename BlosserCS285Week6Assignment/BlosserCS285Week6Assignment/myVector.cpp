#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class myVector : public vector<T> 
{
public:
	bool sorted = true;
	int seqSearch(T searchItem);
	int binarySearch(T searchItem);
	void bubbleSort();
	void insertionSort();
};

template <class T>
int myVector<T>::seqSearch(T searchItem)
{
	//implement sequential search
	int length = this->size();
	for (int i = 0; i < length; i++)
	{
		if (searchItem == this->at(i))
		{
			return i;
		}
	}
	return -1;
}

template <class T>
int myVector<T>::binarySearch(T searchItem)
{
	//implement binary search
	if (this->sorted == false)
	{
		this->bubbleSort();
	}
	int first = 0;
	int last = this->size() - 1;

	while (first <= last)
	{
		int mid = (first + last) / 2;

		if (this->at(mid) == searchItem)
		{
			return mid;
		}
		else if (this->at(mid) > searchItem)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}

	return -1;

}

template <class T>
void myVector<T>::bubbleSort()
{
	//implement bubble sort
	int n = this->size();
	T temp;

	for (int j = 0; j < n; j++)
	{
		for (int i = j + 1; i < n - 1; i++)
		{
			if (this->at(j) > this->at(i))
			{
				temp = this->at(j);
				this->at(j) = this->at(i);
				this->at(i) = temp;
			}
		}
	}
}

template <class T>
void myVector<T>::insertionSort()
{
	//implement insertion sort
	int n = this->size();

	for (int i = 1; i < n; i++)
	{
		T temp = this->at(i);
		int j = i - 1;

		while (j >= 0 && this->at(j) > temp)
		{
			this->at(j + 1) = this->at(j);
			j--;
		}
		this->at(j + 1) = temp;
	}
	this->sorted = true;
}

int main()
{
	//define test vector(s)
	myVector<string> nameList;

	//add values to the vector(s)
	nameList.push_back("Eric");
	nameList.push_back("Kaitlyn");
	nameList.push_back("Koltyn");
	nameList.push_back("Kyle");

	//test sort methods
	nameList.bubbleSort();
	nameList.insertionSort();

	//test search methods
	cout << endl;
	cout << "Test Search Methods:" << endl;
	cout << "Eric is present in the list and located at index: " << nameList.seqSearch("Eric") << endl;
	cout << "Koltyn is present in the list and located at index: " << nameList.binarySearch("Koltyn") << endl;
	cout << endl;
	
	//print sorted vector using range based for loop
	cout << "Name List Vector: " << endl;
	for (int i = 0; i < nameList.size(); i++)
	{
		cout << nameList.at(i) << endl;
	}

		//define new test vector(s)
		myVector<int> numberList;
		myVector<string> gunList;

		//define an iterator to each of the above vector containers
		myVector<int>::iterator it1;
		myVector<string>::iterator it2;

		//add values to the vector(s)
		numberList.push_back(10);
		numberList.push_back(136);
		numberList.push_back(42);
		numberList.push_back(25);
		numberList.push_back(67);
		gunList.push_back("Ruger");
		gunList.push_back("Sig Sauer");
		gunList.push_back("Remington");
		gunList.push_back("Browning");

		//test the STL sort method
		sort(numberList.begin(), numberList.end());
		sort(gunList.begin(), gunList.end());

		 //test the STL binary_search algorithm
		cout << endl;
		cout << "Test Binary Search:" << endl;
		if (binary_search(numberList.begin(), numberList.end(), 25))
		{
			cout << "25 exists in Number List Vector" << endl;
		}
		else
		{
			cout << "25 does not exist in Number List Vector" << endl;
		}

		if (binary_search(numberList.begin(), numberList.end(), 26))
		{
			cout << "26 exists in Number List Vector" << endl;
		}
		else
		{
			cout << "26 does not exist in Number List Vector" << endl;
		}

		if (binary_search(gunList.begin(), gunList.end(), "Ruger"))
		{
			cout << "Ruger exists in Gun List Vector" << endl;
		}
		else
		{
			cout << "Ruger does not exist in Gun List Vector" << endl;
		}

		if (binary_search(gunList.begin(), gunList.end(), "Glock"))
		{
			cout << "Glock exists in Gun List Vector" << endl;
		}
		else
		{
			cout << "Glock does not exist in Gun List Vector" << endl;
		}

		//print the resulting vector(s) using an iterator
		cout << endl;
		cout << "Number List Vector: " << endl;
		for (it1 = numberList.begin(); it1 != numberList.end(); it1++)
		{
			cout << *it1 << endl;
		}

		cout << endl;
		cout << "Job List Vector: " << endl;
		for (it2 = gunList.begin(); it2 != gunList.end(); it2++)
		{
			cout << *it2 << endl;
		}
	return 0;

}
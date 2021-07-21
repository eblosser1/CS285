#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
#include <cassert>

#include "stackADT.h"

using namespace std;

template <class Type>
class stackType : public stackADT<Type>
{
public:
	const stackType<Type>& operator=(const stackType<Type>&);

	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;

	void push(const Type& newItem);
	Type top() const;
	void pop();

	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();

	void push(vector<Type> lists);

private:
	int maxStackSize;
	int stackTop;
	Type* list;

	void copyStack(const stackType<Type>& otherStack);
};

template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
try {
	if (!isFullStack())
	{
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		throw 501;
}
catch (int sizeNum)
{
	cout << "Cannot add to a full stack." << endl;
}

//VECTOR OVERLOAD
template <class Type>
void stackType<Type>::push(vector<Type> lists)
{
	for (int i = 0; i < lists.size(); i++)
		lists.push_back(lists[i]);
}

template <class Type>
Type stackType<Type>::top() const
try {
	if (stackTop != 0)
		return list[stackTop - 1];
	else
		throw 503;
}
catch (int granthasizeNum)
{
	cout << "Cannot be called on an empty stack." << endl;
}


template <class Type>
void stackType<Type>::pop()
try {
	if (!isEmptyStack())
		stackTop--;
	else
		throw 502;
}
catch (int sizeNum)
{
	cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType(int stackSize)
try {
	if (stackSize <= 0)
	{
		throw 505;
		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;
	
	stackTop = 0;
	list = new Type[maxStackSize];
}
catch (int sizeNum)
{
	cout << "Size of the array to hold the stack must be positive." << endl;
	cout << "Creating an array of size 100." << endl;
}

template <class Type>
stackType<Type>::~stackType()
{
	delete[] list;
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxStackSize];

	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = nullptr;
	copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
	if (this != &otherStack)
		copyStack(otherStack);

	return *this;
}
#endif
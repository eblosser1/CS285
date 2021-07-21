#include <iostream>
#include <vector>
#include <queue>

#include "myStack.h"

using namespace std;

int main()
{
	stackType<int> stack1(50);
	stackType<int> stack2(50);

	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

	stack2 = stack1;

	cout << "Stack1 Top = " << stack1.top() << " & Stack2 Top = " << stack2.top() << endl;
	if (stack1.top() == stack2.top())
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.pop();
	stack2.push(32);

	cout << "Stack1 Top = " << stack1.top() << " & Stack2 Top = " << stack2.top() << endl;
	if (stack1.top() == stack2.top())
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.push(11);

	cout << "****After pop and push operations on stack2****" << endl;
	cout << "Stack1 Top = " << stack1.top() << " & Stack2 Top = " << stack2.top() << endl;
	if (stack1.top() == stack2.top())
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	cout << endl;
	
	//Queue
	cout << "Queue: " << endl;
	queue<stackType<int>> que;
	que.push(stack1);
	que.push(stack2);

	while (que.empty() == false)
	{
		stackType<int> stack = que.front();

		while (stack.isEmptyStack() == false)
		{
			int top = stack.top();
			stack.pop();
			cout << top << endl;
		}
		que.pop();
	}
	return 0;

}
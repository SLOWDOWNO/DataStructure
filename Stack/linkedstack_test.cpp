
//Create by Alex Shi on 2022/10/30

# include "linkedstack.h"
# include <iostream>
# include <string>
using namespace std;

int main()
{
	Linkedstack<int > fuck_stack;
	fuck_stack.push(1);
	fuck_stack.push(2);

	cout << "ջ�Ĵ�С: " << fuck_stack.size() << endl;
	cout << "ջ��Ԫ��: " << fuck_stack.getTop() << endl;

	while (!fuck_stack.isEmpty())
	{
		fuck_stack.pop();
	}

	cout << "ջ�Ĵ�С: " << fuck_stack.size() << endl;
	return 0;
}
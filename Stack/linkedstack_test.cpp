
//Create by Alex Shi on 2022/10/30

# include "linkedstack.h"
# include <iostream>
# include <string>
using namespace std;

int main2()
{
	Linkedstack<string> fuck_stack;
	fuck_stack.push("you");
	fuck_stack.push("Fuck");

	cout << "栈的大小: " << fuck_stack.size() << endl;
	cout << "栈顶元素: " << fuck_stack.getTop() << endl;

	while (!fuck_stack.isEmpty())
	{
		fuck_stack.pop();
	}

	cout << "栈的大小: " << fuck_stack.size() << endl;
	return 0;
}
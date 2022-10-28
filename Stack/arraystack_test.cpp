
//Create by Alex Shi on 2022/10/28

# include "arraystack.h"
# include <iostream>
using namespace std;

int main()
{
	ArrayStack<int> stack1(10);
	for (int i = 0; i < 5; i++)
	{
		stack1.push(i);
	}
	cout << "栈的大小： " << stack1.size() << endl;;
	cout << "栈是否为空： " << stack1.isEmpty() << endl;;
	cout << "栈顶元素为：" << stack1.getTop() << endl;
	cout << "依次出栈： " << endl;
	while (!stack1.isEmpty())
	{
		cout << stack1.pop() << " ";
	}
	cout << endl;
	return 0;
}
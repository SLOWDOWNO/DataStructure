
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
	cout << "ջ�Ĵ�С�� " << stack1.size() << endl;;
	cout << "ջ�Ƿ�Ϊ�գ� " << stack1.isEmpty() << endl;;
	cout << "ջ��Ԫ��Ϊ��" << stack1.getTop() << endl;
	cout << "���γ�ջ�� " << endl;
	while (!stack1.isEmpty())
	{
		cout << stack1.pop() << " ";
	}
	cout << endl;
	return 0;
}
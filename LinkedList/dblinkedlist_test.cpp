//双向循环链表测试代码
//Create by Alex Shi on 2022/10/17

#include "dblinkedlist.h"
#include <iostream>
using namespace std;

int main1()
{
	dbLinkedList<int> dblink;
	//inser test
	for (int i = 0; i < 10; i++)
	{
		dblink.insertIndex(0,i+10);
	}
	dblink.insertIndex(0,100);
	dblink.insertTail(1000);
	cout << dblink.getLength() << endl;

	//delete test
	dblink.deleteFirst();
	dblink.deleteTail();
	dblink.deleteIndex(3);

	dbLinkedList<int>::pointer ptr = dblink.getHead();
	ptr = ptr->next_ptr;
	while (ptr != dblink.getHead())
	{
		cout << ptr->_data << " ";
		ptr = ptr->next_ptr;
	}

	return 0;
}

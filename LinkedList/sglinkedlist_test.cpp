
// Created by Alex Shi on 2022/10/24.

#include "sglinkedlist.h"
#include <iostream>

using namespace std;
int main()
{
    sgLinkedList<int> link;
    for (int i = 0; i < 10; i++)
    {
      link.insertIndex(i, i);
    }
    cout << link.getLength() << endl;

    link.insertHead(1111);
    link.insertTail(2222);

    sgLinkedList<int>::pointer ptr = link.getHead();
    while (ptr != nullptr)
    {
        cout << ptr->_data << endl;
        ptr = ptr->_next;
    }

    //getchar();
    return 0;
}
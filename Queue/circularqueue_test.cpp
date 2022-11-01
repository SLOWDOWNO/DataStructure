
//Create by Alex Shi on 2022/11/1
//循环链表的测试文件

# include "circularqueue.h"
# include <iostream>
using namespace std;

int main()
{
    Circularqueue<string> fuck_queue(6);
    fuck_queue.push("one");
    fuck_queue.push("two");
    fuck_queue.push("three");
    fuck_queue.push("four");
    fuck_queue.push("five");
    cout << "队列长度" << fuck_queue.size() << endl;
    while (!fuck_queue.isEmpty())
    {
        cout << fuck_queue.front() << endl;
        fuck_queue.pop();
    }
    return 0;
}
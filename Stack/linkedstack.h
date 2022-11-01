
// Create by Alex Shi on 2022/10/30
// 基于单链表的栈的C++模板实现

# pragma once
# ifndef LINKEDSTACK_H
# define LINKEDSTACK_H

//节点 ADT
template <typename T>
class Node
{
public:
	Node(T value) : _val(value), _next(nullptr) {};
	Node() : _next(nullptr) {};
public:
	T _val;
	Node<T>* _next;
};

//链栈 ADT
//链表头作为栈顶
template <typename T>
class Linkedstack
{
public:
	Linkedstack();
	~Linkedstack();
public:
	bool isEmpty();						//判断是否栈空
	int size();							//栈的大小
	T getTop();							//获取栈顶元素
	void push(T value);					//入栈
	T pop();							//出栈
private:
	Node<T>* phead;						//指向栈顶的头指针
	int count;							//栈的元素数量
};

//构造函数
template <typename T>
Linkedstack<T>::Linkedstack()
	: count(0), phead(nullptr)
{
	phead = new Node<T>();
	phead->_next = nullptr;
}

// 析构函数
template <typename T>
Linkedstack<T>::~Linkedstack()
{
	Node<T>* pnode = phead->_next;
	while (nullptr != pnode)
	{
		Node<T>* ptemp = pnode;
		pnode = pnode->_next;
		delete ptemp;
	}
}

//判断是否栈空
template <typename T>
bool Linkedstack<T>::isEmpty()
{
	return (count == 0);
}

//返回栈的大小
template <typename T>
int Linkedstack<T>::size()
{
	return count;
}

//返回栈顶元素
template <typename T>
T Linkedstack<T>::getTop()
{
	if (phead->_next != nullptr)
	{
		return phead->_next->_val;
	}
	else
	{
		return 0;
	}
}

//入栈 (将节点从链表头插入)
template <typename T>
void Linkedstack<T>::push(T value)
{
	Node<T>* pnewNode = new Node<T>(value);
	phead->_next = pnewNode;
	pnewNode->_next = phead->_next;
	count++;
}

//出栈 (从表头删除元素,并返回其值)
template <typename T>
T Linkedstack<T>::pop()
{
	if (phead->_next != nullptr)
	{
		Node<T>* pdel = phead->_next;
		phead->_next = phead->_next->_next;
		T value = pdel->_val;
		delete pdel;
		count--;
		return value;
	}
	else
	{
		return 0;
	}
}

# endif LINKEDSTACK_H
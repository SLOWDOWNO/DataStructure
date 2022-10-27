
//Create by Alex Shi on 2022/10/26
# pragma once
# ifndef LINKED_LIST_DBLINKEDLIST_H
# define LINKED_LIST_DBLINKEDLIST_H

//双向循环链表节点 ADT
template <typename T>
class Node
{
public:
	Node() = default;
	Node(T data, Node<T>* preptr, Node<T>* nextptr)
		: _data(data), pre_ptr(preptr), next_ptr(nextptr) { }
public:
	T _data;
	Node<T>* pre_ptr;
	Node<T>* next_ptr;
};
//双向循环双链表 ADT
template <typename T>
class dbLinkedList
{
public:
	typedef Node<T>* pointer;
	dbLinkedList();
	~dbLinkedList();
public:
	bool isEmpty();						    //链表是否为空
	int getLength();					    //获取链表长度

	Node<T>* insertIndex(int index, T val); //插入到insert之前
	Node<T>* insertHead(T val);             //头插法插入节点
	Node<T>* insertTail(T val);             //尾插法插入节点

	Node<T>* deleteIndex(int index);        //按索引删除节点
	Node<T>* deleteFirst();				    //删除第一个节点
	Node<T>* deleteTail();				    //删除尾节点

	Node<T>* getHead();					    //获取链表头节点

	T get_index(int index);					//获取索引元素
	T get_front();						    //获取第一个元素
	T get_last();						    //获取最后一个元素
private:
	int length;
	Node<T>* phead;
private:
	Node<T>* getNode(int index);
};

//构造函数
template <typename T>
dbLinkedList<T>::dbLinkedList()
{
	phead = new Node<T>(0, nullptr, nullptr);
	phead->pre_ptr = phead;
	phead->next_ptr = phead;
	length = 0;
}
//析构函数
template <typename T>
dbLinkedList<T>::~dbLinkedList()
{
	Node<T>* ptrNode = phead->next_ptr;
	while (nullptr != ptrNode)
	{
		Node<T>* temp = ptrNode;
		ptrNode = ptrNode->next_ptr;
		delete temp;                   //对所有节点进行销毁
	}
}
//获取链表头节点
template <typename T>
Node<T>* dbLinkedList<T>::getHead()
{
	return phead;
}
//获取链表长度
template <typename T>
int dbLinkedList<T>::getLength()
{
	return length;
}
//获取索引元素
template <typename T>
Node<T>* dbLinkedList<T>::getNode(int index)
{
	if (index >= length || length < 0)
		return nullptr;
	//如果在前半部分
	if (index <= (length / 2))
	{
		Node<T>* pnode = phead->next_ptr;
		while (index)
		{
			pnode = phead->next_ptr;
			index--;
		}
		return pnode;
	}	
	//如果在后半部分
	index = length - index - 1;
	Node<T>* pnode = phead->pre_ptr;
	while (index)
	{
		pnode = pnode->pre_ptr;
		index--;
	}
	return pnode;
}
//新节点插入到表头
template <typename T>
Node<T>* dbLinkedList<T>::insertHead(T val)
{
	Node<T>* newNode = new Node<T>(val, phead, phead->next_ptr);
	phead->next_ptr->pre_ptr = newNode;
	phead->next_ptr = newNode;
	length++;
	return newNode;
};
//新节点插入到表尾
template <typename T>
Node<T>* dbLinkedList<T>::insertTail(T val)
{
	Node<T>* newNode = new Node<T>(val, phead->next_ptr, phead);
	phead->pre_ptr->next_ptr = newNode;
	phead->next_ptr = newNode;
	length++;
	return newNode;
}
//新节点插入到index位置之前
template <typename T>
Node<T>* dbLinkedList<T>::insertIndex(int index, T val)
{
	if (index == 0)
		return insertHead(val);
	Node<T>* pNode = getNode(index);
	if (pNode == nullptr)
		return nullptr;
	Node<T>* newNode = new Node<T>(val, pNode->next_ptr, pNode);
	pNode->pre_ptr->next_ptr = newNode;
	pNode->pre_ptr = newNode;
	length++;

	return newNode;
}
//删除链表第一个节点 返回删除后链表第一个节点
template <typename T>
Node<T>* dbLinkedList<T>::deleteFirst()
{
	if (length == 0)
		return nullptr;
	Node<T>* pnode = phead->next_ptr;
	phead->next_ptr = pnode->next_ptr;
	pnode->next_ptr->pre_ptr = phead;
	delete pnode;
	length--;
	return phead->next_ptr;
}
//删除链表尾节点 返回删除后尾节点
template <typename T>
Node<T>* dbLinkedList<T>::deleteTail()
{
	if (length == 0)
		return nullptr;
	Node<T>* pnode = phead->pre_ptr;
	pnode->pre_ptr->next_ptr = phead;
	phead->pre_ptr = pnode->pre_ptr;
	delete pnode;
	length--;
	return phead->pre_ptr;
}
template <typename T>
Node<T>* dbLinkedList<T>::deleteIndex(int index)
{
	if (index == 0)
		return deleteFirst();
	if (index == length - 1)
		return deleteTail();
	if (index >= length)
		return nullptr;
	Node<T>* pnode = getNode(index);
	pnode->pre_ptr->next_ptr = pnode->next_ptr;
	pnode->next_ptr->pre_ptr = pnode->pre_ptr;

	Node<T>* ptemp = pnode->pre_ptr;
	delete pnode;
	length--;
	return ptemp;
}
//判断链表是否空
template <typename T>
bool dbLinkedList<T>::isEmpty()
{
	return (length == 0);
}
//获取链表第一个元素
template <typename T>
T dbLinkedList<T>::get_front()
{
	return phead->next_ptr->_data;
}
//获取链表尾元素
template <typename T>
T dbLinkedList<T>::get_last()
{
	return phead->pre_ptr->_data;
}
//获取索引元素
template <typename T>
T dbLinkedList<T>::get_index(int index)
{
	if (index > length)
		return nullptr;
	Node<T>* ptrnode = getNode(index);
	T value = ptrnode->_data;
	return value;
}
# endif LINKED_LIST_DBLINKEDLIST_H
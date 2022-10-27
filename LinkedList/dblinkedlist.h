
//Create by Alex Shi on 2022/10/26
# pragma once
# ifndef LINKED_LIST_DBLINKEDLIST_H
# define LINKED_LIST_DBLINKEDLIST_H

//˫��ѭ������ڵ� ADT
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
//˫��ѭ��˫���� ADT
template <typename T>
class dbLinkedList
{
public:
	typedef Node<T>* pointer;
	dbLinkedList();
	~dbLinkedList();
public:
	bool isEmpty();						    //�����Ƿ�Ϊ��
	int getLength();					    //��ȡ������

	Node<T>* insertIndex(int index, T val); //���뵽insert֮ǰ
	Node<T>* insertHead(T val);             //ͷ�巨����ڵ�
	Node<T>* insertTail(T val);             //β�巨����ڵ�

	Node<T>* deleteIndex(int index);        //������ɾ���ڵ�
	Node<T>* deleteFirst();				    //ɾ����һ���ڵ�
	Node<T>* deleteTail();				    //ɾ��β�ڵ�

	Node<T>* getHead();					    //��ȡ����ͷ�ڵ�

	T get_index(int index);					//��ȡ����Ԫ��
	T get_front();						    //��ȡ��һ��Ԫ��
	T get_last();						    //��ȡ���һ��Ԫ��
private:
	int length;
	Node<T>* phead;
private:
	Node<T>* getNode(int index);
};

//���캯��
template <typename T>
dbLinkedList<T>::dbLinkedList()
{
	phead = new Node<T>(0, nullptr, nullptr);
	phead->pre_ptr = phead;
	phead->next_ptr = phead;
	length = 0;
}
//��������
template <typename T>
dbLinkedList<T>::~dbLinkedList()
{
	Node<T>* ptrNode = phead->next_ptr;
	while (nullptr != ptrNode)
	{
		Node<T>* temp = ptrNode;
		ptrNode = ptrNode->next_ptr;
		delete temp;                   //�����нڵ��������
	}
}
//��ȡ����ͷ�ڵ�
template <typename T>
Node<T>* dbLinkedList<T>::getHead()
{
	return phead;
}
//��ȡ������
template <typename T>
int dbLinkedList<T>::getLength()
{
	return length;
}
//��ȡ����Ԫ��
template <typename T>
Node<T>* dbLinkedList<T>::getNode(int index)
{
	if (index >= length || length < 0)
		return nullptr;
	//�����ǰ�벿��
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
	//����ں�벿��
	index = length - index - 1;
	Node<T>* pnode = phead->pre_ptr;
	while (index)
	{
		pnode = pnode->pre_ptr;
		index--;
	}
	return pnode;
}
//�½ڵ���뵽��ͷ
template <typename T>
Node<T>* dbLinkedList<T>::insertHead(T val)
{
	Node<T>* newNode = new Node<T>(val, phead, phead->next_ptr);
	phead->next_ptr->pre_ptr = newNode;
	phead->next_ptr = newNode;
	length++;
	return newNode;
};
//�½ڵ���뵽��β
template <typename T>
Node<T>* dbLinkedList<T>::insertTail(T val)
{
	Node<T>* newNode = new Node<T>(val, phead->next_ptr, phead);
	phead->pre_ptr->next_ptr = newNode;
	phead->next_ptr = newNode;
	length++;
	return newNode;
}
//�½ڵ���뵽indexλ��֮ǰ
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
//ɾ�������һ���ڵ� ����ɾ���������һ���ڵ�
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
//ɾ������β�ڵ� ����ɾ����β�ڵ�
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
//�ж������Ƿ��
template <typename T>
bool dbLinkedList<T>::isEmpty()
{
	return (length == 0);
}
//��ȡ�����һ��Ԫ��
template <typename T>
T dbLinkedList<T>::get_front()
{
	return phead->next_ptr->_data;
}
//��ȡ����βԪ��
template <typename T>
T dbLinkedList<T>::get_last()
{
	return phead->pre_ptr->_data;
}
//��ȡ����Ԫ��
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
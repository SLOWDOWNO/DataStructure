
// Create by Alex Shi on 2022/10/30
// ���ڵ������ջ��C++ģ��ʵ��

# pragma once
# ifndef LINKEDSTACK_H
# define LINKEDSTACK_H

//�ڵ� ADT
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

//��ջ ADT
//����ͷ��Ϊջ��
template <typename T>
class Linkedstack
{
public:
	Linkedstack();
	~Linkedstack();
public:
	bool isEmpty();						//�ж��Ƿ�ջ��
	int size();							//ջ�Ĵ�С
	T getTop();							//��ȡջ��Ԫ��
	void push(T value);					//��ջ
	T pop();							//��ջ
private:
	Node<T>* phead;						//ָ��ջ����ͷָ��
	int count;							//ջ��Ԫ������
};

//���캯��
template <typename T>
Linkedstack<T>::Linkedstack()
	: count(0), phead(nullptr)
{
	phead = new Node<T>();
	phead->_next = nullptr;
}

// ��������
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

//�ж��Ƿ�ջ��
template <typename T>
bool Linkedstack<T>::isEmpty()
{
	return (count == 0);
}

//����ջ�Ĵ�С
template <typename T>
int Linkedstack<T>::size()
{
	return count;
}

//����ջ��Ԫ��
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

//��ջ (���ڵ������ͷ����)
template <typename T>
void Linkedstack<T>::push(T value)
{
	Node<T>* pnewNode = new Node<T>(value);
	phead->_next = pnewNode;
	pnewNode->_next = phead->_next;
	count++;
}

//��ջ (�ӱ�ͷɾ��Ԫ��,��������ֵ)
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
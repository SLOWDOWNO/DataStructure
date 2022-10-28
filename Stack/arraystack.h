
//Create by Alex Shi on 2022/10/28
//���������ջ��C++ģ��ʵ��
#pragma once

# ifndef ARRAYSTACK_H
# define ARRAYSTACK_H

template <typename T>
class ArrayStack
{
public:
	ArrayStack(int cpcity);																																																																								
	~ArrayStack();
public:
	bool isEmpty();							//�ж��Ƿ��
	int size();								//�鿴��ǰջ�Ĵ�С
	T getTop();								//��ȡջ��Ԫ��
	void push(T element);							//��ջ
	T pop();								//��ջ
private:
	int count;								//ջ��Ԫ������
	const int capacity;							//ջ������
	T* array;								//�ײ����ݽṹΪ����
};

//���캯��
template <typename T>
ArrayStack<T>::ArrayStack(int cpcity)
	: count(0), capacity(cpcity - 1), array(nullptr)
{
	array = new T[capacity];				//�����������10��cpcity=10,capacity��Χ��0~9
}

//��������
template <typename T>
ArrayStack<T>::~ArrayStack()
{
	if (array)
	{
		delete array;
		array = nullptr;
	}
}

//�ж��Ƿ��
template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return (count == 0);
}

//�鿴��ǰջ�Ĵ�С
template <typename T>
int ArrayStack<T>::size()
{
	return count;
}

//��ȡջ��Ԫ��
template <typename T>
T ArrayStack<T>::getTop()
{
	if (count != 0)
	{
		return array[count - 1];
	}
}

//��ջ ����һ��Ԫ�� ��С+1
template <typename T>
void ArrayStack<T>::push(T element)
{
	//���ջû��
	if (count != (capacity + 1))
	{
		array[count++] = element;
	}
}

//��ջ
template <typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)
	{
		return array[--count];
	}
}

# endif ARRAYSTACK_H
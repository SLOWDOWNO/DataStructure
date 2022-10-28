
//Create by Alex Shi on 2022/10/28
//基于数组的栈的C++模板实现
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
	bool isEmpty();							//判断是否空
	int size();								//查看当前栈的大小
	T getTop();								//获取栈顶元素
	void push(T element);							//入栈
	T pop();								//出栈
private:
	int count;								//栈内元素数量
	const int capacity;							//栈的容量
	T* array;								//底层数据结构为数组
};

//构造函数
template <typename T>
ArrayStack<T>::ArrayStack(int cpcity)
	: count(0), capacity(cpcity - 1), array(nullptr)
{
	array = new T[capacity];				//传入的容量是10，cpcity=10,capacity范围是0~9
}

//析构函数
template <typename T>
ArrayStack<T>::~ArrayStack()
{
	if (array)
	{
		delete array;
		array = nullptr;
	}
}

//判断是否空
template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return (count == 0);
}

//查看当前栈的大小
template <typename T>
int ArrayStack<T>::size()
{
	return count;
}

//获取栈顶元素
template <typename T>
T ArrayStack<T>::getTop()
{
	if (count != 0)
	{
		return array[count - 1];
	}
}

//入栈 进入一个元素 大小+1
template <typename T>
void ArrayStack<T>::push(T element)
{
	//如果栈没满
	if (count != (capacity + 1))
	{
		array[count++] = element;
	}
}

//出栈
template <typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)
	{
		return array[--count];
	}
}

# endif ARRAYSTACK_H
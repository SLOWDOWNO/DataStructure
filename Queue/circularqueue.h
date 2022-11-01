
//Create by Alex Shi on 2022/11/1
//基于数组的循环队列的C++模板实现


# ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

template <typename T>
class Circularqueue
{
public:
	Circularqueue(int cpcity);
	~Circularqueue();
public:
	bool isEmpty();							//队列判空
	int size();								//队列大小
	bool push(T value);						//入队
	bool pop();								//出队
	T front();								//取队首元素
private:
	int capacity;							//队列容量
	int begin;								//队首标志
	int end;								//队尾标志
	T* queue;
};

//构造函数
template <typename T>
Circularqueue<T>::Circularqueue(int cpcity)
	: capacity(cpcity - 1), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];
}

//析构函数
template <typename T>
Circularqueue<T>::~Circularqueue()
{
	delete[] queue;
}

//判断队列是否空
template <typename T>
bool Circularqueue<T>::isEmpty()
{
	if (begin == end)
	{
		return true;
	}
	else
		return false;
}

//返回队列长度
template <typename T>
int Circularqueue<T>::size()
{
	return ((end - begin + capacity) % capacity);
}

//元素入队并返回状态
template <typename T>
bool Circularqueue<T>::push(T value)
{
	if ((end + 1) % capacity == begin)
	{
		return false;
	}
	queue[end] = value;
	end = (end + 1) % capacity;
	return true;
}

//元素出队并返回状态
template <typename T>
bool Circularqueue<T>::pop()
{
	if (this->isEmpty())
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
}

//返回队首元素
template <typename T>
T Circularqueue<T>::front()
{
	if (this->isEmpty())
	{
		return 0;
	}
	return queue[begin];
}

# endif CIRCULAR_QUEUE_H


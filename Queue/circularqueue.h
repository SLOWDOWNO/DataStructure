
//Create by Alex Shi on 2022/11/1
//���������ѭ�����е�C++ģ��ʵ��


# ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

template <typename T>
class Circularqueue
{
public:
	Circularqueue(int cpcity);
	~Circularqueue();
public:
	bool isEmpty();							//�����п�
	int size();								//���д�С
	bool push(T value);						//���
	bool pop();								//����
	T front();								//ȡ����Ԫ��
private:
	int capacity;							//��������
	int begin;								//���ױ�־
	int end;								//��β��־
	T* queue;
};

//���캯��
template <typename T>
Circularqueue<T>::Circularqueue(int cpcity)
	: capacity(cpcity - 1), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];
}

//��������
template <typename T>
Circularqueue<T>::~Circularqueue()
{
	delete[] queue;
}

//�ж϶����Ƿ��
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

//���ض��г���
template <typename T>
int Circularqueue<T>::size()
{
	return ((end - begin + capacity) % capacity);
}

//Ԫ����Ӳ�����״̬
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

//Ԫ�س��Ӳ�����״̬
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

//���ض���Ԫ��
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


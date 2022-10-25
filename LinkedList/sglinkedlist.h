//
// Created by Alex Shi on 2022/10/24.
//

#ifndef LINKED_LIST_SGLINKEDLIST_H
#define LINKED_LIST_SGLINKEDLIST_H
//������ڵ����ݽṹ
template <typename T>
class Node
{
public:
    T _data;
    Node<T>* _next;
public:
    Node() = default;
    Node(T value, Node* next)
        : _data(value), _next(next) {}
};
//���������ݽṹ
template <typename T>
class sgLinkedList
{
public:
    typedef Node<T>* pointer;
    //���캯�� �� ��������
    sgLinkedList();
    ~sgLinkedList();
    //
public:
    void printList();        //��ӡ����
    bool isEmpty();          //�����Ƿ�Ϊ��
    int getLength();         //������

    //T getData(int index);    //����������ȡ����
    //T getHeadData();         //��ȡ��һ���ڵ������
    //T getLastData();         //��ȡβ�ڵ�����

    Node<T>* insertIndex(int index, T val);      //����������ڵ�
    Node<T>* insertHead(T val);       //ͷ�巨����ڵ�
    Node<T>* insertTail(T val);       //β�巨����ڵ�

    //void clear();            //�������
    Node<T>* deleteIndex(int index);       //������ɾ���ڵ�
    Node<T>* deleteFirst();       //ɾ����һ���ڵ�
    Node<T>* deleteTail();        //ɾ��β�ڵ�

    Node<T>* getHead();      //��ȡ������Ԫ�ڵ�
private:
    int length = 0;              //�����ȣ�
    Node<T>* phead;  //ͷָ��
private:
    Node<T>* getNode(int index);    //��ȡָ��λ�õĽڵ�
};

//------------------�ӿڵ�ʵ��------------------------
//Ĭ�Ϲ��캯��
template <typename T>
sgLinkedList<T>::sgLinkedList()
    :length(0), phead(nullptr)
{
    //����ͷ�ڵ�
    phead = new Node<T>();
    phead->_next = nullptr;
}
//��ȡ����λ�õ�ǰһ���ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::getNode(int index)
{
    if (index > length || index < 0)
        return nullptr;
    int temp = 0;
    Node<T>* ptrNode = phead;
    while (temp < index)
    {
        temp++;
        ptrNode = ptrNode->_next;
    }
    return ptrNode;
}
//��������
template <typename T>
sgLinkedList<T>::~sgLinkedList()
{
    Node<T>* ptrNode = phead->_next;
    while (nullptr != ptrNode)
    {
        Node<T>* temp = ptrNode;
        ptrNode = ptrNode->_next;
        delete temp;                //�����нڵ��������
    }
}
//���������С
template <typename T>
int sgLinkedList<T>::getLength()
{
    return length;
}
//�����п�
template <typename T>
bool sgLinkedList<T>::isEmpty()
{
    return length == 0;
}
//��ȡ��Ԫ�ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::getHead()
{
    return phead->_next;
}
//���������½ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::insertIndex(int index, T val)
{
    Node<T>* preNode = getNode(index);
    if (preNode)
    {
        Node<T>* newNode = new Node<T>(val, preNode->_next);
        preNode->_next = newNode;
        length++;
        return newNode;
    }
    return nullptr;
}
//��ͷ������
template <typename T>
Node<T>* sgLinkedList<T>::insertHead(T val)
{
    return insertIndex(0, val);
}
//��β������
template <typename T>
Node<T>* sgLinkedList<T>::insertTail(T val)
{
    return insertIndex(length, val);
}
//������ɾ���ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::deleteIndex(int index)
{
    if (isEmpty())
        return nullptr;
    Node<T>* ptrNode = getNode(index);
    Node<T>* delNode = ptrNode->_next;
    ptrNode->_next = delNode->_next;
    length--;
    return ptrNode->_next;
}
//ɾ����Ԫ�ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::deleteFirst()
{
    deleteIndex(1);
}
//ɾ��β�ڵ�
template <typename T>
Node<T>* sgLinkedList<T>::deleteTail()
{
    deleteIndex(length);
}
#endif LINKED_LIST_SGLINKEDLIST_H

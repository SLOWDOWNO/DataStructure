//
// Created by Alex Shi on 2022/10/24.
//

#ifndef LINKED_LIST_SGLINKEDLIST_H
#define LINKED_LIST_SGLINKEDLIST_H
//单链表节点数据结构
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
//单链表数据结构
template <typename T>
class sgLinkedList
{
public:
    typedef Node<T>* pointer;
    //构造函数 和 析构函数
    sgLinkedList();
    ~sgLinkedList();
    //
public:
    void printList();        //打印链表
    bool isEmpty();          //链表是否为空
    int getLength();         //链表长度

    //T getData(int index);    //根据索引获取数据
    //T getHeadData();         //获取第一个节点的数据
    //T getLastData();         //获取尾节点数据

    Node<T>* insertIndex(int index, T val);      //按索引插入节点
    Node<T>* insertHead(T val);       //头插法插入节点
    Node<T>* insertTail(T val);       //尾插法插入节点

    //void clear();            //清空链表
    Node<T>* deleteIndex(int index);       //按索引删除节点
    Node<T>* deleteFirst();       //删除第一个节点
    Node<T>* deleteTail();        //删除尾节点

    Node<T>* getHead();      //获取链表首元节点
private:
    int length = 0;              //链表长度；
    Node<T>* phead;  //头指针
private:
    Node<T>* getNode(int index);    //获取指定位置的节点
};

//------------------接口的实现------------------------
//默认构造函数
template <typename T>
sgLinkedList<T>::sgLinkedList()
    :length(0), phead(nullptr)
{
    //创建头节点
    phead = new Node<T>();
    phead->_next = nullptr;
}
//获取索引位置的前一个节点
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
//析构函数
template <typename T>
sgLinkedList<T>::~sgLinkedList()
{
    Node<T>* ptrNode = phead->_next;
    while (nullptr != ptrNode)
    {
        Node<T>* temp = ptrNode;
        ptrNode = ptrNode->_next;
        delete temp;                //对所有节点进行销毁
    }
}
//返回链表大小
template <typename T>
int sgLinkedList<T>::getLength()
{
    return length;
}
//链表判空
template <typename T>
bool sgLinkedList<T>::isEmpty()
{
    return length == 0;
}
//获取首元节点
template <typename T>
Node<T>* sgLinkedList<T>::getHead()
{
    return phead->_next;
}
//索引插入新节点
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
//从头部插入
template <typename T>
Node<T>* sgLinkedList<T>::insertHead(T val)
{
    return insertIndex(0, val);
}
//从尾部插入
template <typename T>
Node<T>* sgLinkedList<T>::insertTail(T val)
{
    return insertIndex(length, val);
}
//按索引删除节点
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
//删除首元节点
template <typename T>
Node<T>* sgLinkedList<T>::deleteFirst()
{
    deleteIndex(1);
}
//删除尾节点
template <typename T>
Node<T>* sgLinkedList<T>::deleteTail()
{
    deleteIndex(length);
}
#endif LINKED_LIST_SGLINKEDLIST_H

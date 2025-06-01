#include <iostream>
using namespace std;

template <class T>
class node
{
private:
    T value;
    node<T> *previous;
    node<T> *next;

public:
    void setValue(T v)
    {
        value = v;
    }
    T getValue()
    {
        return value;
    }
    void setPrevious(node<T> *p)
    {
        previous = p;
    }
    node<T> *getPrevious()
    {
        return previous;
    }
    void setNext(node<T> *n)
    {
        next = n;
    }
    node<T> *getNext()
    {
        return next;
    }
};

template <class T>
class MyQueue
{
private:
    node<T> head;
    node<T> tail;
    int myQueueSize;

public:
    MyQueue()
    {
        head.setPrevious(nullptr);
        head.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        myQueueSize = 0;
    }
    void enqueue(T item)
    {
        node<T> *newnode = new node<T>;
        newnode->setValue(item);
        newnode->setPrevious(tail.getPrevious());
        newnode->setNext(&tail);
        tail.getPrevious()->setNext(newnode);
        tail.setPrevious(newnode);
        myQueueSize++;
    }
    T dequeue()
    {
        T ret = head.getNext()->getValue();
        head.setNext(head.getNext()->getNext());
        delete head.getNext()->getPrevious();
        head.getNext()->setPrevious(&head);
        if (myQueueSize != 0)
            myQueueSize--;
        return ret;
    }
    int length()
    {
        return myQueueSize;
    }
    T frontValue()
    {
        return head.getNext()->getValue();
    }
    T rearValue()
    {
        return tail.getPrevious()->getValue();
    }
    T leaveQueue()
    {
        T ret = tail.getPrevious()->getValue();
        tail.setPrevious(tail.getPrevious()->getPrevious());
        delete tail.getPrevious()->getNext();
        tail.getPrevious()->setNext(&tail);
        if (myQueueSize != 0)
            myQueueSize--;
        return ret;
    }
    void clear()
    {
        node<T> *del = head.getNext();
        for (int i = 0; i < myQueueSize; i++)
        {
            node<T> *temp = del->getNext();
            delete del;
            del = temp;
        }
        head.setPrevious(nullptr);
        head.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        myQueueSize = 0;
    }
    void display()
    {
        if (myQueueSize == 0)
        {
            cout << "< >" << endl;
            return;
        }
        node<T> dis;
        dis.setPrevious(&head);
        dis.setNext(head.getNext());
        cout << "< | ";
        for (int i = 0; i < myQueueSize; i++)
        {
            cout << dis.getNext()->getValue() << ' ';
            dis.setNext(dis.getNext()->getNext());
        }
        cout << '>';
        cout << endl;
    }
    ~MyQueue()
    {
        this->clear();
    }
};
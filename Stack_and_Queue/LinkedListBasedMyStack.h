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
class MyStack
{
private:
    node<T> head;
    node<T> tail;
    int myStackSize;

public:
    MyStack()
    {
        head.setPrevious(nullptr);
        head.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        myStackSize = 0;
    }
    void push(T item)
    {
        node<T> *newnode = new node<T>;
        newnode->setValue(item);
        newnode->setPrevious(tail.getPrevious());
        newnode->setNext(&tail);
        tail.getPrevious()->setNext(newnode);
        tail.setPrevious(newnode);
        myStackSize++;
    }
    T pop()
    {
        T ret = tail.getPrevious()->getValue();
        tail.setPrevious(tail.getPrevious()->getPrevious());
        delete tail.getPrevious()->getNext();
        tail.getPrevious()->setNext(&tail);
        if (myStackSize != 0)
            myStackSize--;
        return ret;
    }
    int length()
    {
        return myStackSize;
    }
    T topValue()
    {
        return tail.getPrevious()->getValue();
    }
    void clear()
    {
        node<T> *del = head.getNext();
        for (int i = 0; i < myStackSize; i++)
        {
            node<T> *temp = del->getNext();
            delete del;
            del = temp;
        }
        head.setPrevious(nullptr);
        head.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        myStackSize = 0;
    }
    void display()
    {
        if (myStackSize == 0)
        {
            cout << "< >" << endl;
            return;
        }
        node<T> dis;
        dis.setPrevious(&head);
        dis.setNext(head.getNext());
        cout << "< ";
        for (int i = 0; i < myStackSize; i++)
        {
            if (i == myStackSize - 1)
                cout << "| ";
            cout << dis.getNext()->getValue() << ' ';
            dis.setNext(dis.getNext()->getNext());
        }
        cout << ">";
        cout << endl;
    }
    ~MyStack()
    {
        this->clear();
    }
};
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
class MyList
{
private:
    node<T> currentPosition;
    node<T> head;
    node<T> tail;
    int currentPositionBar;
    int myListSize;

public:
    MyList()
    {
        head.setPrevious(nullptr);
        head.setNext(&tail);
        currentPosition.setPrevious(&head);
        currentPosition.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        currentPositionBar = 0;
        myListSize = 0;
    }
    int size()
    {
        return myListSize;
    }
    void push(T item)
    {
        node<T> *newNode = new node<T>;
        newNode->setValue(item);
        newNode->setPrevious(currentPosition.getPrevious());
        newNode->setNext(currentPosition.getNext());
        currentPosition.getNext()->setPrevious(newNode);
        currentPosition.getPrevious()->setNext(newNode);
        currentPosition.setNext(newNode);
        myListSize++;
    }
    void pushBack(T item)
    {
        node<T> *newNode = new node<T>;
        newNode->setValue(item);
        newNode->setPrevious(tail.getPrevious());
        newNode->setNext(&tail);
        tail.getPrevious()->setNext(newNode);
        tail.setPrevious(newNode);
        if (currentPosition.getNext() == &tail)
            currentPosition.setNext(newNode);
        myListSize++;
    }
    T erase()
    {
        T ret = currentPosition.getNext()->getValue();
        delete currentPosition.getNext();
        currentPosition.setNext(currentPosition.getNext()->getNext());
        currentPosition.getNext()->setPrevious(currentPosition.getPrevious());
        currentPosition.getPrevious()->setNext(currentPosition.getNext());
        if (currentPosition.getNext() == &tail)
            this->prev();
        if (myListSize != 0)
            myListSize--;
        return ret;
    }
    void setToBegin()
    {
        currentPosition.setPrevious(&head);
        currentPosition.setNext(head.getNext());
        currentPositionBar = 0;
    }
    void setToEnd()
    {
        currentPosition.setNext(tail.getPrevious());
        currentPosition.setPrevious(tail.getPrevious()->getPrevious());
        currentPositionBar = myListSize - 1;
    }
    void prev()
    {
        if (currentPosition.getPrevious()->getPrevious() != nullptr)
        {
            currentPosition.setNext(currentPosition.getPrevious());
            currentPosition.setPrevious(currentPosition.getPrevious()->getPrevious());
            currentPositionBar--;
        }
    }
    void next()
    {
        if (currentPositionBar != myListSize - 1)
        {
            currentPosition.setPrevious(currentPosition.getNext());
            currentPosition.setNext(currentPosition.getNext()->getNext());
            currentPositionBar++;
        }
    }
    int currPos()
    {
        return currentPositionBar;
    }
    int setToPos(int pos)
    {
        if (pos >= 0 && pos < myListSize)
        {
            currentPosition.setPrevious(&head);
            currentPosition.setNext(head.getNext());
            for (int i = 1; i <= pos; i++)
            {
                currentPosition.setPrevious(currentPosition.getNext());
                currentPosition.setNext(currentPosition.getNext()->getNext());
            }
            currentPositionBar = pos;
        }
        return currentPositionBar;
    }
    T getValue()
    {
        return currentPosition.getNext()->getValue();
    }
    int find(T item)
    {
        node<T> findNode;
        findNode.setPrevious(&head);
        findNode.setNext(head.getNext());
        for (int i = 0; i < myListSize; i++)
        {
            if (findNode.getNext()->getValue() == item)
                return i;
            findNode.setNext(findNode.getNext()->getNext());
        }
        return -1;
    }
    void clear()
    {
        node<T> *del = head.getNext();
        for (int i = 0; i < myListSize; i++)
        {
            node<T> *temp = del->getNext();
            delete del;
            del = temp;
        }
        head.setPrevious(nullptr);
        head.setNext(&tail);
        currentPosition.setPrevious(&head);
        currentPosition.setNext(&tail);
        tail.setPrevious(&head);
        tail.setNext(nullptr);
        currentPositionBar = 0;
        myListSize = 0;
    }
    void display()
    {
        node<T> dis;
        dis.setPrevious(&head);
        dis.setNext(head.getNext());
        cout << '<';
        for (int i = 0; i < myListSize; i++)
        {
            if (i == currentPositionBar)
                cout << "| ";
            cout << dis.getNext()->getValue();
            if (i != myListSize - 1)
                cout << ' ';
            dis.setNext(dis.getNext()->getNext());
        }
        cout << '>' << endl;
    }
    ~MyList()
    {
        this->clear();
    }
};
#include <iostream>
using namespace std;

template <class T>
class MyList
{
private:
    int myListSize = 0;
    int myListCapacity = 1;
    int currentPosition = 0;
    T *array;

public:
    MyList(int X)
    {
        myListCapacity = X;
        array = new T[myListCapacity];
    }
    MyList()
    {
        array = new T[myListCapacity];
    }
    int capacity()
    {
        return myListCapacity;
    }
    int size()
    {
        return myListSize;
    }
    void push(T item)
    {
        if (myListSize + 1 > myListCapacity)
        {
            T *temp;
            temp = new T[myListCapacity * 2];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myListCapacity *= 2;
        }
        for (int i = myListSize; i > currentPosition; i--)
            array[i] = array[i - 1];
        array[currentPosition] = item;
        myListSize++;
    }
    void pushBack(T item)
    {
        if (myListSize + 1 > myListCapacity)
        {
            T *temp;
            temp = new T[myListCapacity * 2];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myListCapacity *= 2;
        }
        array[myListSize] = item;
        myListSize++;
    }
    T erase()
    {
        T ret = array[currentPosition];
        for (int i = currentPosition; i < myListSize; i++)
            array[i] = array[i + 1];
        myListSize--;
        if (currentPosition == myListSize && currentPosition != 0)
            currentPosition--;
        if (myListCapacity / 2 == myListSize)
        {
            T *temp;
            if (myListCapacity != 1)
                myListCapacity /= 2;
            temp = new T[myListCapacity];
            for (int i = 0; i < myListSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        return ret;
    }
    void setToBegin()
    {
        currentPosition = 0;
    }
    void setToEnd()
    {
        if (myListSize == 0)
            currentPosition = 0;
        else
            currentPosition = myListSize - 1;
    }
    void prev()
    {
        if (currentPosition != 0)
            currentPosition--;
    }
    void next()
    {
        if (currentPosition != myListSize - 1)
            currentPosition++;
    }
    int currPos()
    {
        return currentPosition;
    }
    void setToPos(int pos)
    {
        if (pos < myListSize && pos > -1)
            currentPosition = pos;
    }
    T getValue()
    {
        return array[currentPosition];
    }
    int find(T item)
    {
        for (int i = 0; i < myListSize; i++)
        {
            if (array[i] == item)
                return i;
        }
        return -1;
    }
    void clear()
    {
        delete[] array;
        myListSize = 0;
        myListCapacity = 1;
        currentPosition = 0;
        array = new T[myListCapacity];
    }
    void display()
    {
        cout << "<";
        for (int i = 0; i < myListSize; i++)
        {
            if (i == currentPosition)
                cout << "| ";
            cout << array[i];
            if (i != myListSize - 1)
                cout << ' ';
        }
        cout << ">";
        cout << endl;
    }
    ~MyList()
    {
        this->clear();
    }
};
#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
    int myStackSize = 0;
    int myStackCapacity = 1;
    T *array;

public:
    MyStack(int X)
    {
        myStackCapacity = X;
        array = new T[myStackCapacity];
    }
    MyStack()
    {
        array = new T[myStackCapacity];
    }
    void push(T item)
    {
        if (myStackSize == myStackCapacity)
        {
            T *temp;
            temp = new T[myStackCapacity * 2];
            for (int i = 0; i < myStackSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myStackCapacity *= 2;
        }
        array[myStackSize] = item;
        myStackSize++;
    }
    T pop()
    {
        T ret = array[myStackSize - 1];
        if (myStackSize != 0)
            myStackSize--;
        if (myStackCapacity / 2 == myStackSize)
        {
            T *temp;
            if (myStackCapacity != 1)
                myStackCapacity /= 2;
            temp = new T[myStackCapacity];
            for (int i = 0; i < myStackSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        return ret;
    }
    int length()
    {
        return myStackSize;
    }
    T topValue()
    {
        return array[myStackSize - 1];
    }
    void clear()
    {
        delete[] array;
        myStackCapacity = 1;
        myStackSize = 0;
        array = new T[myStackCapacity];
    }
    void display()
    {
        cout << "< ";
        for (int i = 0; i < myStackSize; i++)
        {
            if (i == myStackSize - 1)
                cout << "| ";
            cout << array[i] << ' ';
        }
        cout << ">";
        cout << endl;
    }
    ~MyStack()
    {
        this->clear();
    }
};
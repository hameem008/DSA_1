#include <iostream>
using namespace std;

template <class T>
class MyQueue
{
private:
    int myQueueSize = 0;
    int myQueueCapacity = 1;
    int head = 0;
    int tail = 0;
    T *array;

public:
    MyQueue(int X)
    {
        myQueueCapacity = X;
        array = new T[myQueueCapacity];
    }
    MyQueue()
    {
        array = new T[myQueueCapacity];
    }
    void enqueue(T item)
    {
        if (tail == myQueueCapacity)
            tail = 0;
        if (head == tail && myQueueSize == myQueueCapacity)
        {
            T *temp;
            temp = new T[myQueueCapacity * 2];
            int j = 0;
            for (int i = head; i < myQueueCapacity; i++, j++)
            {
                temp[j] = array[i];
            }
            for (int i = 0; i < tail; i++, j++)
            {
                temp[j] = array[i];
            }
            delete[] array;
            array = temp;
            myQueueCapacity *= 2;
            tail = myQueueSize;
            head = 0;
        }
        array[tail] = item;
        myQueueSize++;
        tail++;
    }
    T dequeue()
    {
        T ret = array[head];
        if (myQueueSize == 0)
            return ret;
        head++;
        myQueueSize--;
        if (head == myQueueCapacity)
            head = 0;
        if (myQueueCapacity / 2 == myQueueSize)
        {
            T *temp;
            if (myQueueCapacity != 1)
                myQueueCapacity /= 2;
            temp = new T[myQueueCapacity];
            if (tail < head)
            {
                int j = 0;
                for (int i = head; i < myQueueCapacity; i++, j++)
                {
                    temp[j] = array[i];
                }
                for (int i = 0; i < tail; i++, j++)
                {
                    temp[j] = array[i];
                }
                head = 0;
                tail = myQueueSize;
                delete[] array;
                array = temp;
            }
            else
            {
                int j = 0;
                for (int i = head; i < tail; i++, j++)
                {
                    temp[j] = array[i];
                }
                head = 0;
                tail = myQueueSize;
                delete[] array;
                array = temp;
            }
        }
        return ret;
    }
    int length()
    {
        return myQueueSize;
    }
    T frontValue()
    {
        return array[head];
    }
    T rearValue()
    {
        return array[tail - 1];
    }
    T leaveQueue()
    {
        T ret = array[tail - 1];
        if (myQueueSize == 0)
            return ret;
        tail--;
        myQueueSize--;
        if (tail == -1)
            tail = myQueueCapacity;
        if (myQueueCapacity / 2 == myQueueSize)
        {
            T *temp;
            if (myQueueCapacity != 1)
                myQueueCapacity /= 2;
            temp = new T[myQueueCapacity];
            if (tail < head)
            {
                int j = 0;
                for (int i = head; i < myQueueCapacity; i++, j++)
                {
                    temp[j] = array[i];
                }
                for (int i = 0; i < tail; i++, j++)
                {
                    temp[j] = array[i];
                }
                head = 0;
                tail = myQueueSize;

                delete[] array;
                array = temp;
            }
            else
            {
                int j = 0;
                for (int i = head; i < tail; i++, j++)
                {
                    temp[j] = array[i];
                }
                head = 0;
                tail = myQueueSize;
                delete[] array;
                array = temp;
            }
        }
        return ret;
    }
    void clear()
    {
        delete[] array;
        head = 0;
        tail = 0;
        myQueueCapacity = 1;
        myQueueSize = 0;
        array = new T[myQueueCapacity];
    }
    void display()
    {
        if (myQueueSize == 0)
        {
            cout << "< >" << endl;
            return;
        }
        if (head < tail)
        {
            cout << "< | ";
            for (int i = head; i < tail; i++)
            {
                cout << array[i] << " ";
            }
            cout << ">";
            cout << endl;
        }
        else
        {
            cout << "< | ";
            for (int i = head; i < myQueueCapacity; i++)
            {
                cout << array[i] << " ";
            }
            for (int i = 0; i < tail; i++)
            {
                cout << array[i] << " ";
            }
            cout << ">";
            cout << endl;
        }
    }
    ~MyQueue()
    {
        clear();
    }
};
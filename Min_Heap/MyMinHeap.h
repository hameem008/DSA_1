#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class MyMinHeap
{
private:
    int myMinHeapSize;
    int myMinHeapCapacity;
    T *array;
    void BubbleUp(int index) 
    {
        if (index == 1)
            return;
        if (array[index] < array[index / 2])
            swap(array[index], array[index / 2]);
        BubbleUp(index / 2);
    }
    void SinkDown(int index) // Heapify
    {
        if (index * 2 + 1 <= myMinHeapSize)
        {
            if (array[index * 2] < array[index * 2 + 1])
            {
                if (array[index * 2] < array[index])
                    swap(array[index * 2], array[index]);
                SinkDown(index * 2);
            }
            else
            {
                if (array[index * 2 + 1 < array[index]])
                    swap(array[index * 2 + 1], array[index]);
                SinkDown(index * 2 + 1);
            }
        }
        else if (index * 2 <= myMinHeapSize)
        {
            if (array[index * 2] < array[index])
                swap(array[index * 2], array[index]);
            SinkDown(index * 2);
        }
        else
            return;
    }

public:
    MyMinHeap()
    {
        myMinHeapCapacity = 2;
        myMinHeapSize = 0;
        array = new T[myMinHeapCapacity];
    }
    T FindMin()
    {
        return array[1];
    }
    T ExtractMin()
    {
        T ret = array[1];
        swap(array[1], array[myMinHeapSize]);
        if (myMinHeapSize != 0)
            myMinHeapSize--;
        if (myMinHeapSize + 1 == myMinHeapCapacity / 2)
        {
            T *temp;
            if (myMinHeapCapacity != 2)
                myMinHeapCapacity /= 2;
            temp = new T[myMinHeapCapacity];
            for (int i = 1; i <= myMinHeapSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        SinkDown(1);
        return ret;
    }
    void Insert(T key)
    {
        if (myMinHeapSize + 1 >= myMinHeapCapacity)
        {
            T *temp;
            temp = new T[myMinHeapCapacity * 2];
            for (int i = 1; i <= myMinHeapSize; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            myMinHeapCapacity *= 2;
        }
        myMinHeapSize++;
        array[myMinHeapSize] = key;
        BubbleUp(myMinHeapSize);
    }
    void DecreaseKey(T prevKey, T newKey)
    {
        int index = -1;
        for (int i = 1; i <= myMinHeapSize; i++)
        {
            if (array[i] == prevKey)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
            return;
        array[index] = newKey;
        BubbleUp(index);
    }
    void Print(int lv = 0)
    {
        if (pow(2, lv) <= myMinHeapSize)
            cout << "Level " << lv << ": ";
        for (int i = pow(2, lv); i <= pow(2, lv + 1) - 1; i++)
        {
            if (i == myMinHeapSize + 1)
            {
                if (i != pow(2, lv))
                    cout << endl;
                return;
            }
            cout << array[i] << ' ';
        }
        cout << endl;
        Print(lv + 1);
    }
    ~MyMinHeap()
    {
        delete[] array;
        myMinHeapCapacity = 2;
        myMinHeapSize = 0;
    }
};
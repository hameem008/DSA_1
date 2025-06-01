#include <iostream>
#include "ArrayBasedMyQueue.h"
#include "ArrayBasedMyStack.h"
// #include "LinkedListBasedMyQueue.h"
// #include "LinkedListBasedMyStack.h"
// #include "LinkedListBasedMyQueue&MyStack.h"
// include the header files following the guidence in readme.txt
using namespace std;

int main()
{
    int capacity, size;
    cin >> size >> capacity;
    MyQueue<int> mq;
    MyStack<int> ms;
    for (int i = 0; i < size; i++)
    {
        int in;
        cin >> in;
        mq.enqueue(in);
        ms.push(in);
    }
    mq.display();
    ms.display();
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        int a, b, ret = -1;
        cin >> a >> b;
        if (a == 1)
        {
            mq.clear();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 2)
        {
            mq.enqueue(b);
            cout << ret << endl;
            mq.display();
        }
        else if (a == 3)
        {
            ret = mq.dequeue();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 4)
        {
            ret = mq.length();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 5)
        {
            ret = mq.frontValue();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 6)
        {
            ret = mq.rearValue();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 7)
        {
            ret = mq.leaveQueue();
            cout << ret << endl;
            mq.display();
        }
        else if (a == 8)
        {
            ms.clear();
            cout << ret << endl;
            ms.display();
        }
        else if (a == 9)
        {
            ms.push(b);
            cout << ret << endl;
            ms.display();
        }
        else if (a == 10)
        {
            ret = ms.pop();
            cout << ret << endl;
            ms.display();
        }
        else if (a == 11)
        {
            ret = ms.length();
            cout << ret << endl;
            ms.display();
        }
        else if (a == 12)
        {
            ret = ms.topValue();
            cout << ret << endl;
            ms.display();
        }
    }
}
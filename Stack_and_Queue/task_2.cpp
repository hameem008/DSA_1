#include <iostream>
#include "ArrayBasedMyQueue.h"
#include "ArrayBasedMyStack.h"
// #include "LinkedListBasedMyQueue.h"
// #include "LinkedListBasedMyStack.h"
// #include "LinkedListBasedMyQueue&MyStack.h"
// include the header files following the guidence in readme.txt
class MyTupple
{
public:
    int index;
    int timestamp;
    int duration;
};
int main()
{
    MyQueue<MyTupple> console_1_queue;
    MyStack<MyTupple> console_2_stack;
    int queue_var, stack_var;
    bool qv = true, sv = true;
    int n, c;
    cin >> n >> c;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        MyTupple mt;
        mt.index = i;
        cin >> mt.timestamp >> mt.duration;
    queue:
        if (qv)
        {
            queue_var = mt.timestamp;
            qv = false;
        }
        if (mt.timestamp >= queue_var)
        {

            if (console_1_queue.length() == 0)
            {
                queue_var = max(mt.timestamp, queue_var) + mt.duration;
                array[mt.index] = queue_var;
                continue;
            }
            else
            {
                while (console_1_queue.length() != 0)
                {
                    MyTupple ans;
                    ans = console_1_queue.frontValue();

                    if (mt.timestamp < queue_var)
                        break;
                    queue_var = max(ans.timestamp, queue_var) + ans.duration;
                    array[ans.index] = queue_var;
                    console_1_queue.dequeue();
                }
            }
        }

        if (console_1_queue.length() <= 2)
        {
            console_1_queue.enqueue(mt);
            continue;
        }
    stack:
        if (sv)
        {
            stack_var = mt.timestamp;
            sv = false;
        }
        if (mt.timestamp > stack_var)
        {
            if (console_2_stack.length() == 0)
            {
                stack_var = max(stack_var, mt.timestamp) + mt.duration;
                array[mt.index] = stack_var;
                continue;
            }
            else
            {
                while (console_2_stack.length() != 0)
                {
                    MyTupple ans;
                    ans = console_2_stack.topValue();
                    if (mt.timestamp < stack_var)
                        break;
                    stack_var = max(ans.timestamp, stack_var) + ans.duration;
                    array[ans.index] = stack_var;
                    console_2_stack.pop();
                }
            }
        }
        console_2_stack.push(mt);
    }
    while (console_1_queue.length() != 0)
    {
        MyTupple ans;
        ans = console_1_queue.frontValue();
        queue_var = max(ans.timestamp, queue_var) + ans.duration;
        array[ans.index] = queue_var;
        console_1_queue.dequeue();
    }
    while (console_2_stack.length() != 0)
    {
        MyTupple ans;
        ans = console_2_stack.topValue();
        stack_var = max(ans.timestamp, stack_var) + ans.duration;
        array[ans.index] = stack_var;
        console_2_stack.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] > c)
            array[i] = c;
        cout << i + 1 << " > " << array[i] << endl;
    }
}
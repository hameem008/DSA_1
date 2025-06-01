#include <iostream>
#include "ArrayBasedMyList.h"
using namespace std;

int main()
{
    MyList<int> m;
    m.pushBack(1);
    m.display();
    m.erase();
    m.pushBack(2);
    m.display();
    cout << m.capacity();
}
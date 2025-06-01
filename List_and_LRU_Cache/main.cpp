#include <iostream>
// #include "ArrayBasedMyList.h"
#include "LinkedListBasedMyList.h"
using namespace std;

int main()
{
    FILE *fin, *fout;
    fin = freopen("list_input.txt", "r", stdin);
    fout = freopen("list_output.txt", "w", stdout);
    int n, k;
    cin >> k >> n;
    MyList<int> ml;
    int p;
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        ml.pushBack(p);
    }
    ml.setToPos(0);
    ml.display();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, ret = -1;
        cin >> a >> b;
        if (a == 1)
        {
            ml.display();
            ret = ml.size();
        }
        else if (a == 2)
        {
            ml.push(b);
            ml.display();
        }
        else if (a == 3)
        {
            ml.pushBack(b);
            ml.display();
        }
        else if (a == 4)
        {
            ret = ml.erase();
            ml.display();
        }
        else if (a == 5)
        {
            ml.setToBegin();
            ml.display();
        }
        else if (a == 6)
        {
            ml.setToEnd();
            ml.display();
        }
        else if (a == 7)
        {
            ml.prev();
            ml.display();
        }
        else if (a == 8)
        {
            ml.next();
            ml.display();
        }
        else if (a == 9)
        {
            ret = ml.currPos();
            ml.display();
        }
        else if (a == 10)
        {
            ml.setToPos(b);
            ml.display();
        }
        else if (a == 11)
        {
            ml.display();
            ret = ml.getValue();
        }
        else if (a == 12)
        {
            ml.display();
            ret = ml.find(b);
        }
        else if (a == 13)
        {
            ml.clear();
            ml.display();
        }
        cout << ret << endl;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
#include <iostream>
#include "MyMinHeap.h"
using namespace std;

int main()
{
    FILE *fin;
    FILE *fout;
    fin = freopen("inputTest.txt", "r", stdin);
    fout = freopen("output.txt", "w", stdout);
    MyMinHeap<int> mh;
    while (!feof(fin))
    {
        string cmd;
        int in;
        cin >> cmd;
        if (cmd == "INS")
        {
            cin >> in;
            mh.Insert(in);
            cout << "INSERTED " << in << endl;
        }
        else if (cmd == "PRI")
        {
            cout << "Printing the binary heap …" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
            mh.Print();
            cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
        }
        else if (cmd == "EXT")
        {
            cout << "ExtractMin returned " << mh.ExtractMin() << endl;
        }
        else if (cmd == "DEC")
        {
            int prevKey, newKey;
            cin >> prevKey >> newKey;
            mh.DecreaseKey(prevKey, newKey);
            cout << prevKey << " decreased to " << newKey << endl;
        }
        else if (cmd == "FIN")
        {
            cout << "FindMin returned " << mh.FindMin() << endl;
        }
    }
    fclose(fin);
    fclose(fout);
}
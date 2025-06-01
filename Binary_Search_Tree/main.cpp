#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
    FILE *fin;
    FILE *fout;
    fin = freopen("input.txt", "r", stdin);
    fout = freopen("output.txt", "w", stdout);
    MyBST<int> bst;
    while (!feof(fin))
    {
        char ch;
        string str;
        int n;
        cin >> ch;
        if (ch == 'I')
        {
            cin >> n;
            cout << ch << " " << n << " ";
            bst.Insert(n);
            bst.display();
        }
        else if (ch == 'F')
        {
            cin >> n;
            cout << ch << " " << n << " ";
            if (bst.Find(n))
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
        else if (ch == 'T')
        {
            cin >> str;
            if (str == "Pre")
                bst.PreorderTraversal();
            else if (str == "Post")
                bst.PostorderTraversal();
            else if (str == "In")
                bst.InorderTraversal();
        }
        else if (ch == 'D')
        {
            cin >> n;
            cout << ch << " " << n << " ";
            bst.Delete(n);
            bst.display();
        }
    }
    fclose(fin);
    fclose(fout);
}
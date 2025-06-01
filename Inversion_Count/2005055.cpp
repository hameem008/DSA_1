#include <iostream>
#include <deque>
using namespace std;

int inversionCount;

deque<int> merge_it(deque<int> &a, deque<int> &b)
{
    deque<int> ret;
    int lim = a.size() + b.size();
    while (lim--)
    {
        if (a.size() != 0 && b.size() != 0)
        {
            if (a.front() > b.front())
            {
                ret.push_back(b.front());
                inversionCount += a.size();
                b.pop_front();
            }
            else
            {
                ret.push_back(a.front());
                a.pop_front();
            }
        }
        else if (a.size() != 0 && b.size() == 0)
        {
            ret.push_back(a.front());
            a.pop_front();
        }
        else if (a.size() == 0 && b.size() != 0)
        {
            ret.push_back(b.front());
            b.pop_front();
        }
        else
            break;
    }
    return ret;
}

deque<int> divideAndSort(deque<int> d)
{
    if (d.size() == 1)
        return d;
    else if (d.size() == 2)
    {
        if (d[0] > d[1])
        {
            inversionCount++;
            swap(d[0], d[1]);
            return d;
        }
        else
            return d;
    }
    int hi = d.size(), lo = 0, mid = (hi + lo) / 2;
    deque<int> a, b;
    for (int i = lo; i <= mid; i++)
        a.push_back(d[i]);
    for (int i = mid + 1; i < hi; i++)
        b.push_back(d[i]);
    a = divideAndSort(a);
    b = divideAndSort(b);
    return merge_it(a, b);
}

int main()
{
    int n;
    cin >> n;
    deque<int> d(n);
    for (auto &x : d)
        cin >> x;
    inversionCount = 0;
    divideAndSort(d);
    cout << inversionCount << endl;
    cout << "The inverted pairs are: ";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i] > d[j])
                cout << '(' << d[i] << ',' << d[j] << ')' << ' ';
        }
    }
    cout << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> customers;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        customers.push_back({v, u});
    }
    sort(customers.begin(), customers.end());
    int current_end = -1;
    vector<pair<int, int>> ans;
    for (auto x : customers)
    {
        if (x.second >= current_end)
        {
            ans.push_back({x.second, x.first});
            current_end = x.first;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first << ' ' << x.second << endl;
    }
}
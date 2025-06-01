#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int dp[1000][1000];
vector<pair<int, int>> v;
multiset<int> selected;

int solve(int w, int i)
{
    if (i == 0)
        return 0;
    if (w == 0)
        return 0;
    
    if (dp[w][i] >= 0) return dp[w][i];
    int a = solve(w, i - 1);
    int b = w >= v[i].first ? solve(w - v[i].first, i - 1) + v[i].second : 0;
    return dp[w][i] = max(a, b);
}

void find_selected_items(int w, int i)
{
    if (i == 0 || w == 0)
        return;
    int a = dp[w][i - 1];
    int b = w >= v[i].first ? dp[w - v[i].first][i - 1] + v[i].second : 0;
    if (a > b)
        find_selected_items(w, i - 1);
    else
    {
        selected.insert(v[i].first);
        find_selected_items(w - v[i].first, i - 1);
    }
}

int main()
{
    int items, weight;
    cin >> items;
    for (int i = 0; i < items; i++)
    {
        int w, p;
        cin >> w >> p;
        v.push_back({w, p});
    }
    cin >> weight;
    v.push_back({0, 0});
    sort(v.begin(), v.end());
    cout << solve(weight, items) << endl;
    find_selected_items(weight, items);
    for (auto x : selected)
        cout << x << " ";
    cout << endl;
}
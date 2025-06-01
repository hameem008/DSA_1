#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int source, vector<vector<int>> &graph, vector<bool> &isVisited, vector<vector<int>> &printBFS)
{
    queue<int> q;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        int vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                printBFS[vertex].push_back(x);
                q.push(x);
                isVisited[x] = true;
            }
        }
    }
}

void dfs(int vertex, vector<vector<int>> &graph, vector<bool> &isVIsited, vector<vector<int>> &printDFS)
{
    isVIsited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            printDFS[vertex].push_back(x);
            dfs(x, graph, isVIsited, printDFS);
        }
    }
}

int main()
{
    FILE *fin;
    FILE *fout;
    // fin = freopen("input.txt", "r", stdin);
    // fout = freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> printBFS(n + 1);
    vector<vector<int>> printDFS(n + 1);
    vector<bool> isVisitedDFS(n + 1, false), isVisitedBFS(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int source;
    cin >> source;
    bfs(source, graph, isVisitedBFS, printBFS);
    dfs(source, graph, isVisitedDFS, printDFS);
    cout << "BFS tree" << endl;
    for (int i = 0; i < printBFS.size(); i++)
    {
        if (printBFS[i].size() != 0)
            cout << i << " -> ";
        for (int j = 0; j < printBFS[i].size(); j++)
        {
            cout << printBFS[i][j];
            if (j != printBFS[i].size() - 1)
                cout << ",";
        }
        if (printBFS[i].size() != 0)
            cout << endl;
    }
    cout << "DFS tree" << endl;
    for (int i = 0; i < printDFS.size(); i++)
    {
        if (printDFS[i].size() != 0)
            cout << i << " -> ";
        for (int j = 0; j < printDFS[i].size(); j++)
        {
            cout << printDFS[i][j];
            if (j != printDFS[i].size() - 1)
                cout << ",";
        }
        if (printDFS[i].size() != 0)
            cout << endl;
    }
    fclose(fin);
    fclose(fout);
}
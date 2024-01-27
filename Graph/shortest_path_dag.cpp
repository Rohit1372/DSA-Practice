// Directed Acyclic Graph

#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addAdjacent(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "] ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                dfs(i.first, visited, s);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &s)
    {
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto j : adj[top])
                {
                    if (dist[top] + j.second < dist[j.first])
                    {
                        dist[j.first] = dist[top] + j.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;

    g.addAdjacent(1, 3, 6);
    g.addAdjacent(1, 2, 2);
    g.addAdjacent(0, 1, 5);
    g.addAdjacent(0, 2, 3);
    g.addAdjacent(3, 4, -1);
    g.addAdjacent(2, 4, 4);
    g.addAdjacent(2, 5, 2);
    g.addAdjacent(2, 3, 7);
    g.addAdjacent(4, 5, -2);

    g.printAdj();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, s);

    cout << endl;
    cout << "Answer is : " << endl;

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addAdj(int u, int v, bool direction)
    {

        // 0 -> undirected
        // 1 -> directed

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{

    graph g;

    int n, ed;
    cout << "Enter Nodes : ";
    cin >> n;

    cout << "Enter edges : ";
    cin >> ed;

    for (int i = 0; i < ed; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addAdj(u, v, 0);
    }

    g.printAdj();
}
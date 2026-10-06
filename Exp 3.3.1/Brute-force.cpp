#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int destination,
         vector<vector<int>>& adj,
         vector<bool>& visited)
{
    if (node == destination)
        return true;

    visited[node] = true;

    for (int next : adj[node])
    {
        if (!visited[next])
        {
            if (dfs(next, destination, adj, visited))
                return true;
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination)
{
    vector<vector<int>> adj(n);

    for (auto& edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);

    return dfs(source, destination, adj, visited);
}

int main()
{
    int n = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    int source = 0;
    int destination = 2;

    bool answer = validPath(n, edges, source, destination);

    cout << (answer ? "true" : "false") << endl;

    return 0;
}

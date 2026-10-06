#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination)
{
    
    vector<vector<int>> adj(n);

    
    for (auto& edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    if (source == destination)
        return true;

    vector<bool> visited(n, false);

    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : adj[node])
        {
            if (next == destination)
                return true;

        
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {
        if (color[start] != -1) {
            continue;
        }

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int u = 0; u < n; u++) {
        int k;
        cin >> k;

        graph[u].resize(k);

        for (int i = 0; i < k; i++) {
            cin >> graph[u][i];
        }
    }

    cout << (isBipartite(graph) ? "true" : "false");

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n + 1), rank_(n + 1, 0) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (rank_[u] < rank_[v]) {
            swap(u, v);
        }

        parent[v] = u;

        if (rank_[u] == rank_[v]) {
            rank_[u]++;
        }

        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);
    vector<int> cand1, cand2;

    for (auto& e : edges) {
        if (parent[e[1]] == 0) {
            parent[e[1]] = e[0];
        } else {
            cand1 = {parent[e[1]], e[1]};
            cand2 = e;
        }
    }

    DSU dsu(n);

    for (auto& e : edges) {
        if (e == cand2) {
            continue;
        }

        if (!dsu.unite(e[0], e[1])) {
            if (cand1.empty()) {
                return e;
            }
            return cand1;
        }
    }

    return cand2;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = findRedundantDirectedConnection(edges);

    cout << "[" << result[0] << "," << result[1] << "]";

    return 0;
}

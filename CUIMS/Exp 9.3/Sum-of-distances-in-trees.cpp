
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> cnt, ans;

void dfs1(int u, int par) {
    cnt[u] = 1;

    for (int v : adj[u]) {
        if (v == par) continue;

        dfs1(v, u);
        cnt[u] += cnt[v];
        ans[0] += cnt[v];
    }
}

void dfs2(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;

        ans[v] = ans[u] - cnt[v] + (n - cnt[v]);
        dfs2(v, u);
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    n = N;
    adj.assign(n, {});
    cnt.assign(n, 0);
    ans.assign(n, 0);

    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    return ans;
}

int main() {
    int N, e;
    cin >> N >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> res = sumOfDistancesInTree(N, edges);

    cout << "[";

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ",";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

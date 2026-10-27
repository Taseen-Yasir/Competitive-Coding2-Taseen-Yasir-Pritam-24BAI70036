
#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    if (edges[0][0] == edges[1][0] ||
        edges[0][0] == edges[1][1]) {
        return edges[0][0];
    }

    return edges[0][1];
}

int main() {
    int e;
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << findCenter(edges);

    return 0;
}

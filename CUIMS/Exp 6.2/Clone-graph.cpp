
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int v) : val(v) {}
};

Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& visited) {
    if (node == nullptr) {
        return nullptr;
    }

    if (visited.count(node)) {
        return visited[node];
    }

    Node* clone = new Node(node->val);
    visited[node] = clone;

    for (Node* nbr : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(nbr, visited));
    }

    return clone;
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "[]";
        return 0;
    }

    vector<Node*> nodes;

    for (int i = 1; i <= n; i++) {
        nodes.push_back(new Node(i));
    }

    for (int i = 0; i < n; i++) {
        int degree;
        cin >> degree;

        for (int j = 0; j < degree; j++) {
            int neighbor;
            cin >> neighbor;
            nodes[i]->neighbors.push_back(nodes[neighbor - 1]);
        }
    }

    unordered_map<Node*, Node*> visited;
    cloneGraph(nodes[0], visited);

    cout << "[";

    for (int i = 0; i < n; i++) {
        Node* clone = visited[nodes[i]];

        if (i > 0) {
            cout << ",";
        }

        cout << "[";

        for (int j = 0; j < (int)clone->neighbors.size(); j++) {
            if (j > 0) {
                cout << ",";
            }

            cout << clone->neighbors[j]->val;
        }

        cout << "]";
    }

    cout << "]";

    return 0;
}

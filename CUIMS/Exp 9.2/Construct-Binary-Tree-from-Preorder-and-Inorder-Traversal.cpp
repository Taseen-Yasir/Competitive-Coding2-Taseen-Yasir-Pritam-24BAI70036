
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& pre, int preL, int preR,
                int inL, int inR, unordered_map<int, int>& idx) {
    if (preL > preR) {
        return nullptr;
    }

    int rootVal = pre[preL];
    int mid = idx[rootVal];
    int leftSize = mid - inL;

    TreeNode* node = new TreeNode(rootVal);

    node->left = build(pre, preL + 1, preL + leftSize,
                       inL, mid - 1, idx);

    node->right = build(pre, preL + leftSize + 1, preR,
                        mid + 1, inR, idx);

    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> idx;

    for (int i = 0; i < (int)inorder.size(); i++) {
        idx[inorder[i]] = i;
    }

    return build(preorder, 0, (int)preorder.size() - 1,
                 0, (int)inorder.size() - 1, idx);
}

void levelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]";
        return;
    }

    queue<TreeNode*> q;
    vector<string> result;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (!cur) {
            result.push_back("null");
        } else {
            result.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
    }

    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    cout << "[";

    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << ",";
        cout << result[i];
    }

    cout << "]";
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);
    levelOrder(root);

    return 0;
}

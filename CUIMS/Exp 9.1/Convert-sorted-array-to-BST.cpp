
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& nums, int lo, int hi) {
    if (lo > hi) {
        return nullptr;
    }

    int mid = lo + (hi - lo + 1) / 2;

    TreeNode* node = new TreeNode(nums[mid]);
    node->left = build(nums, lo, mid - 1);
    node->right = build(nums, mid + 1, hi);

    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, (int)nums.size() - 1);
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
        if (i > 0) {
            cout << ",";
        }
        cout << result[i];
    }

    cout << "]";
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    TreeNode* root = sortedArrayToBST(nums);
    levelOrder(root);

    return 0;
}

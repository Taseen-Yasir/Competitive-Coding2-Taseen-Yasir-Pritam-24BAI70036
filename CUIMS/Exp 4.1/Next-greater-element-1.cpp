#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge;
    stack<int> st;

    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            nge[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }

    vector<int> result;

    for (int num : nums1) {
        result.push_back(nge[num]);
    }

    return result;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> nums1(n);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cin >> m;

    vector<int> nums2(m);

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> res = nextGreaterElement(nums1, nums2);

    cout << "[";

    for (int i = 0; i < (int)res.size(); i++) {
        if (i > 0) cout << ",";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

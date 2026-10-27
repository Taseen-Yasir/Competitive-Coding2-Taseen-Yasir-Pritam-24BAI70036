
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }

        if (i < n) {
            st.push(i);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = nextGreaterElements(nums);

    cout << "[";

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ",";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

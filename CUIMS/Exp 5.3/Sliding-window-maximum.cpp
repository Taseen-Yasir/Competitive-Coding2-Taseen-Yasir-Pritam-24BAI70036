
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < (int)nums.size(); i++) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    vector<int> res = maxSlidingWindow(nums, k);

    cout << "[";

    for (int i = 0; i < (int)res.size(); i++) {
        if (i > 0) cout << ",";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

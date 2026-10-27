
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    double maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum / k;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    cout << findMaxAverage(nums, k);

    return 0;
}

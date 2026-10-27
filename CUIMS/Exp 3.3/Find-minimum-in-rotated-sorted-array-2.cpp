
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int lo = 0, hi = (int)nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        }
        else if (nums[mid] < nums[hi]) {
            hi = mid;
        }
        else {
            hi--;
        }
    }

    return nums[lo];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findMin(nums);

    return 0;
}

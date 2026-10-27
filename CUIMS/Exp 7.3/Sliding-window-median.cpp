
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> low, high;
    vector<double> result;

    auto balance = [&]() {
        while (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }

        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    };

    for (int i = 0; i < (int)nums.size(); i++) {
        if (low.empty() || nums[i] <= *low.rbegin()) {
            low.insert(nums[i]);
        } else {
            high.insert(nums[i]);
        }

        balance();

        if (i >= k) {
            auto it = low.find(nums[i - k]);

            if (it != low.end()) {
                low.erase(it);
            } else {
                high.erase(high.find(nums[i - k]));
            }

            balance();
        }

        if (i >= k - 1) {
            if (k % 2 == 1) {
                result.push_back(*low.rbegin());
            } else {
                result.push_back(
                    ((double)*low.rbegin() + *high.begin()) / 2.0
                );
            }
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

    vector<double> ans = medianSlidingWindow(nums, k);

    cout << fixed << setprecision(1) << "[";

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << ans[i];
    }

    cout << "]";

    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        sort(engineers.rbegin(), engineers.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long speedSum = 0;
        long long result = 0;
        const int MOD = 1000000007;

        for (auto& eng : engineers) {
            int eff = eng.first;
            int spd = eng.second;

            minHeap.push(spd);
            speedSum += spd;

            if (minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            result = max(result, speedSum * eff);
        }

        return result % MOD;
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> speed(n), efficiency(n);

    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> efficiency[i];
    }

    cin >> k;

    Solution obj;
    cout << obj.maxPerformance(n, speed, efficiency, k);

    return 0;
}

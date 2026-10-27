
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    unordered_map<int, int> indexMap;

    for (int i = 0; i < n; i++) {
        indexMap[score[i]] = i;
    }

    vector<int> sorted = score;
    sort(sorted.begin(), sorted.end(), greater<int>());

    vector<string> result(n);

    for (int i = 0; i < n; i++) {
        int origIdx = indexMap[sorted[i]];

        if (i == 0) {
            result[origIdx] = "Gold Medal";
        }
        else if (i == 1) {
            result[origIdx] = "Silver Medal";
        }
        else if (i == 2) {
            result[origIdx] = "Bronze Medal";
        }
        else {
            result[origIdx] = to_string(i + 1);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> score(n);

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    vector<string> res = findRelativeRanks(score);

    cout << "[";

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ", ";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

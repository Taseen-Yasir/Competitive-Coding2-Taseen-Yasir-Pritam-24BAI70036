
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSubseq(vector<int>& nums, int len) {
    int drop = nums.size() - len;
    vector<int> st;

    for (int x : nums) {
        while (drop > 0 && !st.empty() && st.back() < x) {
            st.pop_back();
            drop--;
        }
        st.push_back(x);
    }

    st.resize(len);
    return st;
}

vector<int> mergeSeq(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (lexicographical_compare(b.begin() + j, b.end(),
                                    a.begin() + i, a.end())) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }

    while (i < (int)a.size()) {
        res.push_back(a[i++]);
    }

    while (j < (int)b.size()) {
        res.push_back(b[j++]);
    }

    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> best;

    for (int i = max(0, k - n); i <= min(k, m); i++) {
        vector<int> s1 = maxSubseq(nums1, i);
        vector<int> s2 = maxSubseq(nums2, k - i);
        vector<int> merged = mergeSeq(s1, s2);

        if (merged > best) {
            best = merged;
        }
    }

    return best;
}

int main() {
    int m, n, k;
    cin >> m;

    vector<int> nums1(m);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cin >> n;

    vector<int> nums2(n);

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    cin >> k;

    vector<int> res = maxNumber(nums1, nums2, k);

    cout << "[";

    for (int i = 0; i < (int)res.size(); i++) {
        if (i > 0) cout << ",";
        cout << res[i];
    }

    cout << "]";

    return 0;
}

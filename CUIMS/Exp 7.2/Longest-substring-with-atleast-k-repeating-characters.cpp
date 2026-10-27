
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstring(string s, int k) {
    if (s.size() < k) {
        return 0;
    }

    int freq[26] = {};

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (freq[s[i] - 'a'] < k) {
            int left = longestSubstring(s.substr(0, i), k);
            int right = longestSubstring(s.substr(i + 1), k);
            return max(left, right);
        }
    }

    return s.size();
}

int main() {
    string s;
    int k;

    cin >> s >> k;

    cout << longestSubstring(s, k);

    return 0;
}

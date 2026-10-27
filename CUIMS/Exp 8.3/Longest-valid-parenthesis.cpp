#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    int maxLen = 0;
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    string s;
    getline(cin, s);

    cout << longestValidParentheses(s);

    return 0;
}

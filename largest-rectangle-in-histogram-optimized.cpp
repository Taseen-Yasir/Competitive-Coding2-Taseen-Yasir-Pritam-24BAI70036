#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);

    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = i - left - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    heights.pop_back();

    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << largestRectangleArea(heights);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];

        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            int area = minHeight * (j - i + 1);
            maxArea = max(maxArea, area);
        }
    }

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
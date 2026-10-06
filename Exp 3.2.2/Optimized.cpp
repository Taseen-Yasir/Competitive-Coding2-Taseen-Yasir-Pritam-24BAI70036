#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();

    // Create DP table
    vector<vector<int>> dp(
        m + 1,
        vector<int>(n + 1, 0)
    );

    // Fill DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Characters match
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // Characters don't match
            else
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int answer = longestCommonSubsequence(text1, text2);

    cout << "Length of Longest Common Subsequence = "
         << answer << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string text1, string text2, int i, int j)
{

    if (i == text1.length() || j == text2.length())
        return 0;

    if (text1[i] == text2[j])
    {
        return 1 + LCS(text1, text2, i + 1, j + 1);
    }

    return max(
        LCS(text1, text2, i + 1, j),
        LCS(text1, text2, i, j + 1)
    );
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int answer = LCS(text1, text2, 0, 0);

    cout << "Length of Longest Common Subsequence = "
         << answer << endl;

    return 0;
}

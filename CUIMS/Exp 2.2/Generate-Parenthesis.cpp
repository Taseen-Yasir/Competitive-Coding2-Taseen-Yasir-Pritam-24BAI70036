
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int open, int close, int n, string current, vector<string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generate(open + 1, close, n, current + "(", result);
    }

    if (close < open) {
        generate(open, close + 1, n, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(0, 0, n, "", result);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> res = generateParenthesis(n);

    for (const string& s : res) {
        cout << s << endl;
    }

    return 0;
}

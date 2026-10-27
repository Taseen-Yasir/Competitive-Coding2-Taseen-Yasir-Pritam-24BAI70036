
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0, n = words.size();

    while (i < n) {
        int lineLen = words[i].size();
        int j = i + 1;

        while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
            lineLen += 1 + words[j].size();
            j++;
        }

        int numWords = j - i;
        int totalSpaces = maxWidth - (lineLen - (numWords - 1));
        string line = words[i];

        if (numWords == 1 || j == n) {
            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }

            line += string(maxWidth - line.size(), ' ');
        } else {
            int spaceEach = totalSpaces / (numWords - 1);
            int extra = totalSpaces % (numWords - 1);

            for (int k = i + 1; k < j; k++) {
                int sp = spaceEach + (k - i <= extra ? 1 : 0);
                line += string(sp, ' ') + words[k];
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {
    int n, maxWidth;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cin >> maxWidth;

    for (const string& line : fullJustify(words, maxWidth)) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}

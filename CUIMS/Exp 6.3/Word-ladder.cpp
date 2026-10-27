
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());

    if (words.find(endWord) == words.end()) {
        return 0;
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    words.erase(beginWord);

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord) {
            return steps;
        }

        for (int i = 0; i < (int)word.size(); i++) {
            string temp = word;

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == word[i]) {
                    continue;
                }

                temp[i] = ch;

                if (words.erase(temp)) {
                    q.push({temp, steps + 1});
                }
            }
        }
    }

    return 0;
}

int main() {
    string beginWord, endWord;
    int n;

    cin >> beginWord >> endWord >> n;

    vector<string> wordList(n);

    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    cout << ladderLength(beginWord, endWord, wordList);

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {};

    for (char t : tasks) {
        freq[t - 'A']++;
    }

    int maxFreq = *max_element(freq, freq + 26);
    int countMaxFreq = 0;

    for (int f : freq) {
        if (f == maxFreq) {
            countMaxFreq++;
        }
    }

    int intervals = (maxFreq - 1) * (n + 1) + countMaxFreq;

    return max((int)tasks.size(), intervals);
}

int main() {
    int m, n;
    cin >> m;

    vector<char> tasks(m);

    for (int i = 0; i < m; i++) {
        cin >> tasks[i];
    }

    cin >> n;

    cout << leastInterval(tasks, n);

    return 0;
}

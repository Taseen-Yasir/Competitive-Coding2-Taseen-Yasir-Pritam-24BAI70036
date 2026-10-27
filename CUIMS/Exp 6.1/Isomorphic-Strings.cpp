
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> sToT, tToS;

    for (int i = 0; i < (int)s.size(); i++) {
        char cs = s[i], ct = t[i];

        if (sToT.count(cs) && sToT[cs] != ct) {
            return false;
        }

        if (tToS.count(ct) && tToS[ct] != cs) {
            return false;
        }

        sToT[cs] = ct;
        tToS[ct] = cs;
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << (isIsomorphic(s, t) ? "true" : "false");

    return 0;
}


#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;

    long long lo = 1, hi = x, ans = 1;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (mid * mid == x) {
            return (int)mid;
        }
        else if (mid * mid < x) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return (int)ans;
}

int main() {
    int x;
    cin >> x;

    cout << mySqrt(x);

    return 0;
}


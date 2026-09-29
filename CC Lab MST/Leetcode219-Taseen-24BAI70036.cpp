#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool duplicate(vector<int> a, int k)
{
    unordered_map<int, int> m;

    for (int i = 0; i < a.size(); i++)
    {
        if (m.find(a[i]) != m.end())
        {
            if (i - m[a[i]] <= k)
                return true;
        }

        m[a[i]] = i;
    }

    return false;
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter k: ";
    cin >> k;

    if (duplicate(a, k))
        cout << "Output: true";
    else
        cout << "Output: false";

    return 0;
}
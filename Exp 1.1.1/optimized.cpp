#include <iostream>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(int nums[], int n, int k)
{
    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++)
    {
        if (seen.count(nums[i]) && i - seen[nums[i]] <= k)
            return true;

        seen[nums[i]] = i;
    }

    return false;
}

int main()
{
    int n, k;
    cin >> n;

    int nums[n];

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> k;

    if (containsNearbyDuplicate(nums, n, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}
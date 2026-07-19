#include <iostream>
using namespace std;

bool containsNearbyDuplicate(int nums[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j] && (j - i) <= k)
                return true;
        }
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
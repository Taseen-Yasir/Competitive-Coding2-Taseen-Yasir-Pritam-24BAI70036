#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n;

    int nums[n];

    cout << "Enter the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target: ";
    cin >> t;

    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == t)
        {
            cout << mid;
            return 0;
        }
        else if(nums[mid] < t)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left;

    return 0;
}

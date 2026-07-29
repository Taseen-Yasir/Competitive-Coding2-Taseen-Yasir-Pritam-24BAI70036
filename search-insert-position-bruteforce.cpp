#include <iostream>
using namespace std;

int main()
{
    int t;
    int n;

    cin >> n;

    int nums[n];

    cout << "Enter the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target: ";
    cin >> t;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] >= t)
        {
            cout << i;
            return 0;
        }
    }

    cout << n;

    return 0;
}
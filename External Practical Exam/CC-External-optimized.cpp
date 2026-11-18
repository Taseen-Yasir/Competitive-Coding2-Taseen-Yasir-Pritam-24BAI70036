#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    vector<int> answer(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // Left product
    answer[0] = 1;

    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] * nums[i - 1];

    // Right product
    int right = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= right;
        right *= nums[i];
    }

    cout << "Output: ";
    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";

    return 0;
}
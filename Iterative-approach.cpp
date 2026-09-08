#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> current;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                current.push_back(nums[i]);
            }
        }

        result.push_back(current);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (const auto& subset : result)
    {
        cout << "[";

        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];

            if (i < subset.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}
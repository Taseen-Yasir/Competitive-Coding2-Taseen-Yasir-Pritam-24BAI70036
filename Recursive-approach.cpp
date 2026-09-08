#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums,
               int start,
               vector<int>& current,
               vector<vector<int>>& result)
{
    result.push_back(current);

    for (int i = start; i < nums.size(); i++)
    {
        current.push_back(nums[i]);

        backtrack(nums, i + 1, current, result);

        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> current;

    backtrack(nums, 0, current, result);

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
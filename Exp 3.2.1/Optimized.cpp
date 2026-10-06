#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int a = 1; a <= amount; a++)
    {
    
        for (int coin : coins)
        {
            if (coin <= a)
            {
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }
    }


    if (dp[amount] > amount)
        return -1;

    return dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int answer = coinChange(coins, amount);

    cout << "Minimum number of coins = " << answer << endl;

    return 0;
}

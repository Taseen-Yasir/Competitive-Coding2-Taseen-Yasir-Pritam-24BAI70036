#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int amount, vector<int>& coins)
{
    
    if (amount == 0)
        return 0;

    int best = amount + 1;


    for (int coin : coins)
    {
        if (coin <= amount)
        {
            int result = solve(amount - coin, coins);

            if (result != amount + 1)
            {
                best = min(best, result + 1);
            }
        }
    }

    return best;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int answer = solve(amount, coins);

    if (answer == amount + 1)
        answer = -1;

    cout << "Minimum number of coins = " << answer << endl;

    return 0;
}
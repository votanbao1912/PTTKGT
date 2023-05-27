#include <iostream>
using namespace std;

int countWays(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    int amount;
    cout << "Nh?p s? ti?n c?n ??i: ";
    cin >> amount;

    int ways = countWays(coins, numCoins, amount);
    cout << "S? cách ??i ti?n: " << ways << endl;

    return 0;
}

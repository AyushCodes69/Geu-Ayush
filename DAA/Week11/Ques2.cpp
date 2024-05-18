#include <iostream>
#include <vector>
using namespace std;
int countWaysToMakeSum(int N, const vector<int>& coins) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // There is 1 way to make the sum 0
    for (int coin : coins) {
        for (int j = coin; j <= N; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    return dp[N];
}
int main() {
    int numCoins;
    cout << "Enter the number of coins: ";
    cin >> numCoins;
    vector<int> coins(numCoins);
    cout << "Enter the value of each coin: ";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }
    int N;
    cout << "Enter the value N for which you need to find the sum: ";
    cin >> N;
    int result = countWaysToMakeSum(N, coins);
    cout << "Number of ways to make the sum " << N << " is: " << result << endl;
    return 0;
}

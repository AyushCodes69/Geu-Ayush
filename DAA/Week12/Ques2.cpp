#include <iostream>
#include <vector>
using namespace std;
pair<int, vector<pair<int, int>>> knapsack(int n, vector<int>& weights, vector<int>& values, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    vector<pair<int, int>> selected_items;
    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back({weights[i - 1], values[i - 1]});
            w -= weights[i - 1];
        }
        i--;
    }
    return make_pair(dp[n][capacity], selected_items);
}
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    cout << "Enter values of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    pair<int, vector<pair<int, int>>> result = knapsack(n, weights, values, capacity);
    cout << "Maximum value: " << result.first << endl;
    cout << "Selected items (weight, value): ";
    for (auto item : result.second) {
        cout << "(" << item.first << ", " << item.second << ") ";
    }
    cout << endl;
    return 0;
}

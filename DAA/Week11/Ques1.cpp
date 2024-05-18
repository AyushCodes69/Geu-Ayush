#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1; 
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    vector<int> dims(n + 1);
    cout << "Enter the dimensions of the matrices:" << endl;
    for (int i = 0; i <= n; ++i) {
        cin >> dims[i];
    }
    int result = matrixChainMultiplication(dims);
    cout << "Minimum number of multiplications is: " << result << endl;
    return 0;
}

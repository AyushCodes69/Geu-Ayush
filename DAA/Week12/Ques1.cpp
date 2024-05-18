#include <iostream>
#include <vector>
#include <string>
using namespace std;
pair<int, string> longest_common_subsequence(const string& seq1, const string& seq2) {
    int n = seq1.length();
    int m = seq2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string longest_subsequence = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            longest_subsequence = seq1[i - 1] + longest_subsequence;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return {dp[n][m], longest_subsequence};
}
int main() {
    string seq1, seq2;
    cout << "Enter sequence 1: ";
    cin >> seq1;
    cout << "Enter sequence 2: ";
    cin >> seq2;
    pair<int, string> result = longest_common_subsequence(seq1, seq2);
    cout << "Length of longest common subsequence: " << result.first << endl;
    cout << "Longest common subsequence: " << result.second << endl;
    return 0;
}

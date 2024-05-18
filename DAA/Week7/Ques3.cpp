#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int shortestPathWithKEdges(vector<vector<int>>& graph, int V, int src, int dest, int k) {
    const int INF = INT_MAX;
    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k + 1, INF)));
    for (int i = 0; i < V; ++i) {
        dp[i][i][0] = 0;
    }
    for (int e = 1; e <= k; ++e) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                for (int i = 0; i < V; ++i) {
                    if (graph[u][i] != INF && dp[i][v][e - 1] != INF) {
                        dp[u][v][e] = min(dp[u][v][e], graph[u][i] + dp[i][v][e - 1]);
                    }
                }
            }
        }
    }
    int result = dp[src][dest][k];
    return (result == INF) ? -1 : result;
}
int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INT_MAX; 
            }
        }
    }
    int src, dest, k;
    cin >> src >> dest >> k;
    int result = shortestPathWithKEdges(graph, V, src, dest, k);
    if (result == -1) {
        cout << "no path of length k is available" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}

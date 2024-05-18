#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
typedef pair<int, int> iPair; 
class Graph {
    int V; 
    unordered_map<int, vector<iPair>> adjList; 
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void shortestPath(int src); 
};
Graph::Graph(int V) {
    this->V = V;
}
void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}
void Graph::shortestPath(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adjList[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    cout << "Vertex\t Distance from Source\tPath" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << "\t\t";
        if (dist[i] != INT_MAX) {
            vector<int> path;
            int t = i;
            while (t != -1) {
                path.push_back(t);
                t = parent[t];
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph g(V);
    cout << "Enter the edges (u, v, weight) one by one:" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }
    int source;
    cout << "Enter the source vertex (Akshay's house): ";
    cin >> source;
    g.shortestPath(source);
    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int u, v, weight;
};
class Graph {
    int V; 
    vector<Edge> edges; 
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void bellmanFord(int src); 
};
Graph::Graph(int V) {
    this->V = V;
}
void Graph::addEdge(int u, int v, int weight) {
    edges.push_back({u, v, weight});
}
void Graph::bellmanFord(int src) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src] = 0;
    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    cout << "Vertex\tDistance from Source\tPath" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << "\t\t";
        if (dist[i] != INT_MAX) {
            vector<int> path;
            for (int v = i; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                cout << *it << " ";
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
    g.bellmanFord(source);
    return 0;
}

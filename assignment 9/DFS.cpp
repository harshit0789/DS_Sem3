#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;                           // number of vertices
    vector<vector<int>> adj;         // adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // add edge in graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs function (recursive)
    void dfsUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        // exploring all neighbours
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfsUtil(neighbour, visited);
            }
        }
    }

    // starting point for dfs
    void dfs(int start) {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    // creating a graph with 6 vertices (0 to 5)
    Graph g(6);

    // adding some edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    // perform dfs starting from 0
    g.dfs(0);

    return 0;
}


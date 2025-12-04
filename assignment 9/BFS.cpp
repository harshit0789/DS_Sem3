#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;                         // number of vertices
    vector<vector<int>> adj;       // adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // adding an edge in graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);       // add v in u's list
        adj[v].push_back(u);       // because graph is undirected
    }

    // BFS function
    void bfs(int start) {
        vector<bool> visited(V, false);   // to mark visited nodes
        queue<int> q;

        visited[start] = true;            // mark starting node visited
        q.push(start);

        cout << "BFS Traversal: ";

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // check all neighbours
            for(int neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // making a graph with 6 nodes (0 to 5)
    Graph g(6);

    // adding some edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    // starting BFS from node 0
    g.bfs(0);

    return 0;
}


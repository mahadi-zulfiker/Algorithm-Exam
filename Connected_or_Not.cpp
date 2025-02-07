#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DirectedGraph {
private:
    vector<unordered_set<int>> adjList; // Adjacency list using unordered_set for O(1) average time complexity

public:
    DirectedGraph(int n) {
        adjList.resize(n); // Resize the adjacency list to hold n nodes
    }

    // Function to add a directed edge from node u to node v
    void addEdge(int u, int v) {
        adjList[u].insert(v); // Insert v into the set of u
    }

    // Function to check if there is a direct connection from node A to node B
    bool hasDirectConnection(int A, int B) {
        return adjList[A].find(B) != adjList[A].end(); // Check if B is in the set of A
    }
};

int main() {
    int N, E;
    cin >> N >> E; // Read number of nodes and edges

    DirectedGraph graph(N); // Create a graph with N nodes

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v; // Read edge from u to v
        graph.addEdge(u, v); // Add edge to the graph
    }

    int Q;
    cin >> Q; // Read number of queries

    // Process each query
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B; // Read query nodes A and B
        if (graph.hasDirectConnection(A, B)) {
            cout << "YES" << endl; // Output YES if there is a direct connection
        } else {
            cout << "NO" << endl; // Output NO otherwise
        }
    }

    return 0;
}
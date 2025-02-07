#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;

    // Adjacency matrix to store direct connections
    vector<vector<bool>> adj(N, vector<bool>(N, false));

    // Read edges and mark direct connections
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }

    int Q;
    cin >> Q;

    // Processing queries
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        if (adj[A][B])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

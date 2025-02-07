#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int node;
        cin >> node;
        
        if (adj.find(node) == adj.end() || adj[node].empty()) {
            cout << "-1" << endl;
        } else {
            vector<int> neighbors = adj[node];
            sort(neighbors.rbegin(), neighbors.rend());
            
            for (int i = 0; i < neighbors.size(); i++) {
                if (i > 0) cout << " ";
                cout << neighbors[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}
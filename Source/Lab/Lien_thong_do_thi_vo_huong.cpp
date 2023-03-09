#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int countComponents(int n, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(n+1);
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    int count = 0;
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    int ans = countComponents(n, edges);
    cout << ans << endl;
    return 0;
}

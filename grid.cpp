#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, int parent, vector<vector<int> >& adj, vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<bool>& isArticulation, int& timer) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;

    for (int v = 0; v < adj.size(); ++v) {
        if (adj[u][v] == 0) continue;
        if (v == parent) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, adj, tin, low, visited, isArticulation, timer);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= tin[u])
                isArticulation[u] = true;
            ++children;
        }
    }
    if (parent == -1 && children > 1)
        isArticulation[u] = true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    vector<int> cost(n);
    for (int i = 0; i < n; ++i)
        cin >> cost[i];

    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false), isArticulation(n, false);
    int timer = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i, -1, adj, tin, low, visited, isArticulation, timer);
    }

    int totalCost = 0;
    for (int i = 0; i < n; ++i)
        if (isArticulation[i])
            totalCost += cost[i];

    cout << totalCost << endl;
    return 0;
}

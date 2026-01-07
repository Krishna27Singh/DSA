#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout<<1<<endl;
        return;
    }

    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, 0);
    vector<int> q;
    q.push_back(1);
    dist[1] = 0;
    
    int head = 0;
    while(head<q.size()){
        int u = q[head++];
        for(int v : adj[u]){
            if(dist[v]==-1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push_back(v);
            }
        }
    }

    map<int, int> layerSize;
    vector<int> childrenCnt(n + 1, 0);

    int maxSize = 0;
    for (int i = 1; i <= n; i++) {
        layerSize[dist[i]]++;
        if (parent[i] != 0) {
            childrenCnt[parent[i]]++;
        }
    }

    for (auto const& [d, size] : layerSize) {
        maxSize = max(maxSize, size);
    }

    int maxPone = 0;
    for (int i = 1; i <= n; i++) {
        maxPone = max(maxPone, childrenCnt[i] + 1);
    }

    cout<<max(maxSize, maxPone)<<endl;

    // Output
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& c, vector<int>& ans){
    visited[node] = true;
    bool isLeaf = true;
    bool flag = true;
    for(int neighbour : adj[node]){
        if(!visited[neighbour]){
            isLeaf = false;
            if(c[neighbour] == 0) flag = false;
            dfs(neighbour, adj, visited, c, ans);
        }
    }
    if(c[node] == 1 && !isLeaf && flag) ans.pb(node);   
    if(isLeaf && c[node] == 1) ans.pb(node);
}

void solve(){
    int n; cin>>n;
    vector<int> p(n+1);
    vector<int> c(n+1);
    int root;
    for(int node = 1; node <= n; node++){
        int parent; cin>>parent;
        cin>>c[node];
        p[node] = parent;
        if(parent == -1) root = node;
    }

    vector<int> ans;

    // creating adjacency list for the graph. p[root] == -1 !
    vector<vector<int>> adj(n+1);
    for(int node = 1; node <= n; node++){
        if(p[node] != -1){
            adj[p[node]].pb(node);
            adj[node].pb(p[node]);
        }
    }

    // doing a dfs in the graph and checking if two adjacent nodes have c = 1 and pushing leaf nodes havinng c = 1 in the ans vector
    vector<bool> visited(n+1, false);

    dfs(root, adj, visited, c, ans);

    sort(all(ans));
    
    if(ans.size()) {
        for(int node : ans) cout<<node<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

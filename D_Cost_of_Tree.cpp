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
we need to find the maximum cost for each node


*/

void dfs1(ll u, ll p, vector<vector<ll>> &adj, vector<ll> &a, vector<ll> &base, vector<ll> &sub, vector<ll> &dep, vector<ll> &mdep){
    sub[u] += a[u];
    mdep[u] = dep[u];
    for(ll v : adj[u]){
        if(v==p) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u, adj, a, base, sub, dep, mdep);
        base[u] += base[v] + sub[v];
        sub[u] += sub[v];
        mdep[u] = max(mdep[u], mdep[v]);
    }
}

void dfs2(ll u, ll p, vector<vector<ll>> &adj, vector<ll> &sub, vector<ll>&add, vector<ll>&dep, vector<ll> &mdep){
    int f = 0;
    int s = 0;
    for(ll v : adj[u]){
        if(v==p) continue;
        if(f < mdep[v]) s = f, f = mdep[v];
        else if (s < mdep[v]) s = mdep[v];
    }
    for(ll v : adj[u]){
        if(v==p) continue;
        dfs2(v, u, adj, sub, add, dep, mdep);
        if(f != mdep[v]){
            add[u] = max({add[u], add[v], sub[v]*(f+1-dep[v])});
        }
        else add[u] = max({add[u], add[v], sub[v]*(s+1-dep[v])});
    }
}

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<vector<ll>> adj(n);
    for(ll i = 1; i<n; i++){
        ll u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> base(n), sub(n), dep(n), mdep(n);
    dfs1(0, -1, adj, a, base, sub, dep, mdep);
    vector<ll> add(n);
    dfs2(0, -1, adj, sub, add, dep, mdep);
    for(ll i = 0; i<n; i++) cout<<base[i]+add[i]<<" ";
    cout<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

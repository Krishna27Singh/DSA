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
bob wants to go to the root of the tree

idiot first traversal

if leaf -> go to the parent
nothing is written -> writes L and moves to the left child of that vertex
if L is written -> writes R and moves to the right child of that vertex
if R is written -> erases it and moves to the parent


*/

void dfs1(int node,
          vector<vector<int>> &adj,
          vector<ll> &dp)
{
    // leaf
    if(adj[node].empty()) {
        dp[node] = 1;
        return;
    }

    // special case: root (only 1 child)
    if(adj[node].size() == 1) {
        int child = adj[node][0];
        dfs1(child, adj, dp);
        dp[node] = (dp[child] + 1) % MOD;
        return;
    }

    // normal internal node (2 children)
    int left = adj[node][0];
    int right = adj[node][1];

    dfs1(left, adj, dp);
    dfs1(right, adj, dp);

    dp[node] = (dp[left] + dp[right] + 3) % MOD;
}


void dfs2(int node,
          vector<vector<int>> &adj,
          vector<ll> &dp)
{
    if(adj[node].empty()) return;

    if(adj[node].size() == 1) {
        int child = adj[node][0];
        dp[child] = (dp[child] + dp[node]) % MOD;
        dfs2(child, adj, dp);
        return;
    }

    int left = adj[node][0];
    int right = adj[node][1];

    dp[left] = (dp[left] + dp[node]) % MOD;
    dp[right] = (dp[right] + dp[node]) % MOD;

    dfs2(left, adj, dp);
    dfs2(right, adj, dp);
}


void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    adj[0].push_back(1);

    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;

        if(l != 0) adj[i].push_back(l);
        if(r != 0) adj[i].push_back(r);
    }

    vector<ll> dp(n+1, 0);

    dfs1(0, adj, dp);
    dfs2(0, adj, dp);

    for(int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";
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

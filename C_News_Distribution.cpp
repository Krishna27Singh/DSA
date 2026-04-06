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

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> groups(m, vector<int>());
    for(int i = 0; i<m; i++){
        int k; cin>>k;
        for(int j = 0; j<k; j++){
            int x; cin>>x;
            groups[i].pb(x);
        }
    }

    // we can simply create a graph ! 
    // nodes -> 1 to n

    vector<vector<int>> adj(n+1, vector<int>());
    for(int i = 0; i<m; i++){
        int l = groups[i].size();
        // there is an edge between groups[i][j] and groups[i][j+1]
        for(int j = 0; j<l-1; j++){
            adj[groups[i][j]].pb(groups[i][j+1]);
            adj[groups[i][j+1]].pb(groups[i][j]);
        }
    }

    // iterating the connected components of the graph 
    vector<int> ans(n+1, 0);
    vector<int> vis(n+1, 0);
    for(int node = 1; node <= n; node++){
        if(!vis[node]){
            unordered_map<int, int> mpp;
            // doing the bfs now and doing mpp[node]++ for each node in the bfs
            queue<int> q;
            q.push(node);
            vis[node] = 1;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                mpp[curr]++;
                for(auto it : adj[curr]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            int sizeOfComponent = mpp.size();
            for(auto it : mpp){
                ans[it.first] = max(ans[it.first], sizeOfComponent);
            }
        }
    }

    for(int i =1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

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

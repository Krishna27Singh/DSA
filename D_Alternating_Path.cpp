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

bool checkDFS(int node, int n, vector<vector<int>>& graph, vector<int> &color, int colorToFill, vector<int> &zeroOne, vector<int> &prevIds, vector<int> &vis){
        vis[node] = 1;
        color[node] = colorToFill;
        prevIds.pb(node);
        zeroOne[colorToFill]++;
        for(auto it: graph[node]){
            if(color[it]== -1){
                if(!checkDFS(it, n, graph, color, !colorToFill, zeroOne, prevIds, vis)){
                    for(auto idx : prevIds) color[idx] = -1;
                    return false;
                }
            }
            else if(color[it] == colorToFill) return false;
        }
        return true;
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>());
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int ans = 0;

        vector<int> color(n, -1);
        int colorToFill = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(color[i]==-1 && !vis[i]){
                vector<int> zeroOne(2, 0);
                vector<int> prevIds;
                if(checkDFS(i, n, graph, color, colorToFill, zeroOne, prevIds, vis)){
                    ans += max(zeroOne[0], zeroOne[1]);
                }
            }
        }

    cout<<ans<<endl;

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

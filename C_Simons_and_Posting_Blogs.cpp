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
2 3 1 4          -> 4
2 5 5 6 5        -> 1 
3 4 7 5 5         -> 2
3 6 4 3 1 1 5 4   -> 3
1 1                -> 5

1 

2 3 3 4   -> 5
1 2 4 3 1  -> 2
4 1        -> 3
3 3 1      -> 1
4 3 2 2 2  -> 4


*/

void solve(){
    int n; cin>>n;
    vector<vector<int>> blogs(n);
    for(int i = 0; i<n; i++){
        int l; cin>>l;
        vector<int> users(l);
        for(int j = 0; j<l; j++) cin>>users[j];

        vector<int> newUsers;
        set<int> seen;
        for(int j = l-1; j>=0; j--){
            if(seen.find(users[j]) == seen.end()){
                seen.insert(users[j]);
                newUsers.push_back(users[j]);
            }
        }
        blogs[i] = newUsers;
    }

    vector<bool> dp(1e6+1, false);
    vector<int> q;
    vector<bool> vis(n, false);
    for(int i = 0; i<n; i++){
        int idx = -1;
        vector<int> e;
        for(int j = 0; j<n; j++){
            if(vis[j]) continue;
            vector<int> currE;
            for(auto u: blogs[j]){
                if(!dp[u]) currE.push_back(u);
            }
            if(idx == -1 || currE < e){
                idx = j;
                e = currE;
            }
        }
        vis[idx] = true;
        for(auto u: e){
            dp[u] = true;
            q.push_back(u);
        }
    }
    for(int i = 0; i<q.size(); i++){
        cout<<q[i]<<" ";
    }
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

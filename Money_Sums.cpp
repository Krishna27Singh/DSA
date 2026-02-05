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
f(idx) -> can this sum be achieved or not.

*/

// bool f(int idx, int sum, vector<int> &coins, set<int> &s, vector<vector<int>> &dp){
//     if(idx >= coins.size()){
//         s.insert(sum);
//         return;
//     }

//     // take this coin
//     f(idx+1, sum + coins[idx], coins, s);
//     //not take this coin
//     f(idx+1, sum, coins, s);
// }

void f(int idx, int sum, vector<int> &coins, vector<char> &possible, vector<vector<char>> &vis) {
    if (idx == coins.size()) {
        possible[sum] = 1;
        return;
    }

    if (vis[idx][sum]) return;
    vis[idx][sum] = 1;

    // not take
    f(idx + 1, sum, coins, possible, vis);

    // take
    f(idx + 1, sum + coins[idx], coins, possible, vis);
}

void solve(){
    int n; cin>>n;
    vector<int> coins(n);
    int maxi = 0;
    for(int i = 0; i<n; i++){
        cin>>coins[i];
        maxi += coins[i];
    }
    // vector<vector<int>> dp(n+1, vector<int>(1e5, -1));

    // set<int> s;
    // f(0, 0, coins, s, dp);
    // s.erase(0);
    // cout<<s.size()<<endl;
    // for(auto i: s) cout<<i<<" ";
    // cout<<endl;
    
    vector<vector<char>> vis(n+1, vector<char>(maxi+1, 0));
    vector<char> possible(maxi+1, 0);
    f(0, 0, coins, possible, vis);

    vector<int> ans;
    for (int s = 1; s <= maxi; s++) {
        if (possible[s]) ans.push_back(s);
    }

    cout<<ans.size()<<endl;;
    for(auto i: ans) cout<<i<<" ";
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

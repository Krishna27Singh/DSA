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
f(i) -> number of matching arrays satisfying the description
cases:
curr = last + 1;
curr = last;
curr = last - 1 (if curr is != 1);

*/

int rec(int i, int last, vector<int> &a, int m, vector<vector<int>> &dp){
    if(i == 0){
        int ans = 0;
        if(a[0] == 0){
            for(int v = 1; v <= m; v++){
                ans = (ans + rec(1, v, a, m, dp)) % MOD;
            }
        } else {
            ans = rec(1, a[0], a, m, dp);
        }
        return dp[i][last] = ans;
    }
    if(i == a.size()) return 1;
    if (a[i] != 0 && abs(a[i] - last) > 1) return 0;
    if(dp[i][last] != -1) return dp[i][last];

    int ans = 0;
    if(a[i] == 0){
        if(last - 1 >= 1) ans = (ans + rec(i+1, last-1, a, m, dp)) % MOD;
        ans = (ans + rec(i+1, last, a, m, dp)) % MOD;
        if(last + 1 <= m) ans = (ans + rec(i+1, last+1, a, m, dp)) % MOD;
    } else {
        if(abs(a[i] - last) <= 1)
            ans = rec(i+1, a[i], a, m, dp);
    }
    return dp[i][last] = ans;
}


void solve(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout<<rec(0, 0, a, m, dp)<<endl;

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

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

int rec(int i, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(i == coins.size()) return 0;
    if(dp[i][target] != -1) return dp[i][target];

    int sum = 0;
    int notPick = rec(i+1, target, coins, dp);
    int pick = 0;
    if(target>=coins[i]){
        pick = rec(i, target-coins[i], coins, dp);
    }

    sum = (notPick%MOD + pick%MOD) % MOD;
    return dp[i][target] = sum;
}

void solve(){
    int n, x; cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i<n; i++) cin>>coins[i];
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    // cout<<rec(0, x, coins, dp)<<endl;

    //base case
    for(int i = 0; i<n; i++) dp[i][0] = 1;
    for(int t = 1; t <= x; t++){
        if(t % coins[n-1] == 0)
            dp[n-1][t] = 1;
    }

    for(int i = n-2; i>=0; i--){
        for(int target = 0; target <= x; target++){
            int sum = 0;
            int notPick = dp[i+1][target];
            int pick = 0;
            if(target >= coins[i]){
                pick = dp[i][target-coins[i]];
            }
            sum = (notPick%MOD + pick%MOD) % MOD;
            dp[i][target] = sum;
        }
    }

    cout<<dp[0][x]<<endl;

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

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

int rec(int target, vector<int> &coins, vector<int> &dp){
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];

    int sum = 0;
    for(auto c : coins){
        sum = (sum + (rec(target - c, coins, dp))%MOD)%MOD;
    }

    return dp[target] = sum;
}

void solve(){
    int n, x; cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0; i<n; i++) cin>>coins[i];
    vector<int> dp(x+1, -1);

    cout<<rec(x, coins, dp)<<endl;
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

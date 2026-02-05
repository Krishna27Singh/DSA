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

observations:

at any point if a[i] > a[i+1] -> need to destroy this drop
2 cases possible
1) replace a[i+1] with a[i] -> cost = cost[i+1]
2) replace a[i] with a[i+1] -> cost = cost[i]
2nd case is only possible if i-1>=0 && a[i-1]<=a[i+1]

solve problem on the bases of before, curr, after

we are looking at curr and after

case1
replace after with curr
(before, curr, curr) -> cost = cost[after]

case2
replace curr with after
if after >= before
(before, after, after)

before -> a[idx-1]

implementing in form prevprev, prev a[i]..................

if prev > a[idx]
case1
replace a[idx] with prev -> cost->cost[idx]
prev -> prev
prevprev -> prev

case2
if a[idx] >= prevprev
replace prev with a[idx] -> cost[idx-1]
prev -> a[idx]
prevprev -> a[idx]

dp on these 2 cases

7
5 3 2  5 5 5 4
5 6 9 10 4 2 5
*/

int f(int idx, int prev, vector<int> &a, vector<int> &cost, vector<vector<int>> &dp){
    if(idx >= a.size()) return 0;
    if((prev != -1) && a[idx] < a[prev]) return dp[idx][prev+1] = f(idx+1, prev, a, cost, dp);
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    int take = cost[idx] + f(idx+1, idx, a, cost, dp);
    int notTake = 0 + f(idx+1, prev, a, cost, dp);

    return dp[idx][prev+1] = max(take, notTake);
}

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> cost(n);
    ll ci = 0;
    for(int i = 0; i<n; i++){
        cin>>cost[i];
        ci += cost[i];
    }
    // vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    vector<ll> forward(n+1, 0);
    vector<ll> curr(n+1, 0);

    for(int idx = n-1; idx>=0; idx--){
        for(int prev = n-1; prev>=-1; prev--){
            if((prev != -1) && a[idx] < a[prev]){
                curr[prev+1] = forward[prev+1];
                continue;
            }
            ll take = cost[idx] + forward[idx+1];
            ll notTake = 0 + forward[prev+1];
            curr[prev+1] = max(take, notTake);
        }
        forward = curr;
    }

    cout<<ci-forward[0]<<endl;

    // cout<<ci-f(0, -1, a, cost, dp)<<endl;
    // int prev = a[0];
    // int prevprev = -1e8;
    // cout<<f(1, prev, prevprev, a, cost)<<endl;
    // cout<<f(0, a, cost)<<endl;

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

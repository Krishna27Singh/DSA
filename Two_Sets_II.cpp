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
1, 2, 3, 4,,,,,,,,,,,,,, n
divide in to two subsequence sets such that s1 = s2

n <= 500
O(N*N) or O(N*N*logN)


*/

int f(int idx, int sum, int n, int S, vector<vector<int>> &dp){
    if(idx > n){
        if(2 * sum == S) return 1;
        return 0;
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];

    //don't take element into my sum
    int notTake = f(idx+1, sum, n, S, dp);
    // take this element into my sum
    int take = f(idx+1, idx + sum, n, S, dp);
    return dp[idx][sum] = (take%MOD + notTake%MOD)%MOD;
}

void solve(){
    int n; cin>>n;
    int S = n*(n+1)/2;
    vector<vector<int>> dp(n+1, vector<int>(S+1, -1));

    ll ans = f(1, 0, n, S, dp);
    ll inv2 = (MOD + 1) / 2;
    cout << (ans * inv2) % MOD << '\n';

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

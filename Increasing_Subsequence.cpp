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

int f(int idx, int prev, vector<int> &a, vector<vector<int>> &dp){
    if(idx == a.size()) return 0;
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    int notTake = 0 + f(idx+1, prev, a, dp);
    int take = 0;
    if(prev == -1 || a[idx] > a[prev]) take = 1 + f(idx+1, idx, a, dp);
    return dp[idx][prev+1] = max(take, notTake);
}

void solve(){
    int n; cin>>n;
    vector<int> a(n); 
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    cout<<f(0, -1, a, dp)<<endl;
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

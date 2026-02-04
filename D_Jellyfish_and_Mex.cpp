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
2 cases
if(element to delet > mex) mex is not affected
if(element to delete = mex) mex = mex -1;
if(element to delete < mex) mex = element to delete
*/

int rec(int mex, unordered_map<int, int> &mpp, vector<int> &dp){
    if(mex == 0) return 0;
    if(dp[mex] != -1) return dp[mex];

    int ans = INF;
    for(int dlt = 0; dlt < mex; dlt++){
        int freq = mpp[dlt];
        mpp[dlt] = 0;
        ans = min(ans, (freq-1)*mex + dlt + rec(dlt, mpp, dp));
        mpp[dlt] = freq;
    }
    return dp[mex] = ans;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    
    int mex = 0;
    vector<int> temp(a.begin(), a.end());
    sort(temp.begin(), temp.end());
    for(int x : temp){
        if(x == mex) mex++;
        else if(x > mex) break;
    }

    int ans = 0;
    unordered_map<int ,int> mpp;
    for(auto i: a) mpp[i]++;
    for(auto &[element, freq] : mpp){
        if(element > mex) ans += freq*mex;
    }
    vector<int> dp(n+1, -1);

    cout<<rec(mex, mpp, dp)<<endl;

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

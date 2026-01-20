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
const ll MOD = 998244353;

/*
****************************************** APPROACH **************************************************

*/

ll rec(ll i, ll bal, ll len, ll k, ll n, string &s, vector<vector<vector<vector<ll>>>> &dp){
    if(i==n){
        if(bal == 0 && k==3 && len>0) return len-2;
        else return 0;
    }

    if(dp[i][bal][len][k]!=-1) return dp[i][bal][len][k];
    ll ans = 0;

    ans = (ans + rec(i+1, bal, len, k, n, s, dp))%MOD;

    if(s[i]=='('){
        int temp = k;
        if(k==1 || k==2) temp++;
        ans = (ans + rec(i+1, bal+1, len+1, temp, n, s, dp))%MOD;
    }
    else{
        if(bal>0){
            int temp = k;
            if(k==0) temp++;
            ans = (ans + rec(i+1, bal-1, len+1, temp, n, s, dp))%MOD;
        }
    }

    return dp[i][bal][len][k] = ans;
}


void solve(){
    ll n; cin>>n;
    string s; cin>>s;

    vector<vector<vector<vector<ll>>>> dp(n+1, vector<vector<vector<ll>>>(n+1,vector<vector<ll>>(n+1, vector<ll>(4, -1))));


    ll ans = (rec(0, 0, 0, 0, n, s, dp))%MOD;

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

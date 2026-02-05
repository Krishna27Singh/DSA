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
list of n numbers

alice, bob
alice starts

1) remove first number
2) remove last number

score += number
max score for alice?

maximum score -> 2500 * 1e9

n is eve -> last turn bob
n is odd -> last turn alice
*/


void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    ll s = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s += a[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for(int i = 0; i<n; i++) dp[i][i] = a[i];

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = max(
                a[l] - dp[l + 1][r],
                a[r] - dp[l][r - 1]
            );
        }
    }

    ll ans = (s+dp[0][n-1])/2;
    cout<<ans<<endl;



 
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

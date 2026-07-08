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

/*
****************************************** Testing ****************************************************

*/

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll dp[105][105];
void solve(){
    ll n, m; cin>>n>>m;
    ll cnt = 0;
    for(int i = m; i>=2; i--){
        for(int j = m; j>=2; j--){
            ll lcmm = lcm(i, j);
            if(lcmm > m){
                dp[i][j] = 0;
                continue;
            }
            ll t = (m/i)*(m/j)%MOD;
            t = (t * power(m/lcmm, n-2))%MOD;
            for(int x = 1; i*x <= m; x++){
                for(int y = 1; j*y <= m; y++){
                    if(x == 1 && y == 1) continue;
                    t = (t - dp[i*x][j*y] + MOD)%MOD;
                }
            }
            dp[i][j] = t;
            if(gcd(i, j) == 1){
                cnt = (cnt + dp[i][j])%MOD;
            }
        }
    }
    cout<<cnt<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1; cin >> tc;
    while (tc--) solve();
    return 0;
}

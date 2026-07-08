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

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

const int MOD = 998244353;
const int maxi = 200005;
int dp[maxi];
bool isp[maxi];
vector<int> primes;
ll a[maxi];
ll b[maxi];
ll c[maxi];

void sieve() {
    fill(isp, isp + maxi, true);
    isp[0] = isp[1] = false;
    dp[1] = 1;
    for (int i = 2; i < maxi; ++i) {
        if (isp[i]) {
            primes.push_back(i);
            dp[i] = -1;
        }
        for (int p : primes) {
            if (i * p >= maxi) break;
            isp[i * p] = false;
            if (i % p == 0) {
                dp[i * p] = 0;
                break;
            } else {
                dp[i * p] = -dp[i];
            }
        }
    }
}

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

void solve() {
    ll n, m; cin>>n>>m;

    for (int i = 1; i <= m; ++i) {
        ll fi = (1LL * dp[i] * (m / i)) % MOD;
        if (fi < 0) fi += MOD;
        a[i] = fi;
        b[i] = 0;
        c[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        if (!a[i]) continue;
        for (int j = i; j <= m; j += i) {
            b[j] += a[i];
            if (b[j] >= MOD) b[j] -= MOD;
        }
    }
    for (int i = 1; i <= m; ++i) {
        b[i] = (b[i] * b[i]) % MOD;
    }
    for (int i = 1; i <= m; ++i) {
        if (b[i] == 0) continue;
        for (int j = i, k = 1; j <= m; j += i, ++k) {
            if (dp[k] == 1) {
                c[j] += b[i];
                if (c[j] >= MOD) c[j] -= MOD;
            } else if (dp[k] == -1) {
                c[j] -= b[i];
                if (c[j] < 0) c[j] += MOD;
            }
        }
    }
    ll cnt = 0;
    for (ll L = 1; L <= m; ++L) {
        ll term = (power(m / L, n - 2) * c[L]) % MOD;
        cnt = (cnt + term) % MOD;
    }
    ll si = 0;
    ll sim1 = 0;
    for (ll d = 1; d <= m; ++d) {
        if (dp[d] == 0) continue;
        ll pn = power(m / d, n);
        ll np1 = power(m / d, n - 1);
        
        if (dp[d] == 1) {
            si = (si + pn) % MOD;
            sim1 = (sim1 + np1) % MOD;
        } else if (dp[d] == -1) {
            si = (si - pn + MOD) % MOD;
            sim1 = (sim1 - np1 + MOD) % MOD;
        }
    }
    ll ans = si;
    ll sub = (2LL * m % MOD) * sim1 % MOD;
    ans = (ans - sub % MOD + MOD) % MOD; 
    ans = (ans + cnt) % MOD;            

    cout << ans << "\n";
}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    int tc = 1; cin >> tc;
    while (tc--) solve();
    return 0;
}

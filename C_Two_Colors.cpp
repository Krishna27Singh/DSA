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

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll a) {
    return binpow(a, MOD - 2);
}
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
void buildFact(int n, vector<ll> &fact, vector<ll> &invFact) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = modInverse(fact[n]);
    for (int i = n; i >= 1; i--) invFact[i - 1] = invFact[i] * i % MOD;
}
ll nCr(int n, int r, vector<ll> &fact, vector<ll> &invFact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
ll phi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
        int n, m;
        cin >> n >> m;

        vector<ll> a(m);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            a[i] = min(a[i], (ll)n - 1);
        }

        sort(a.begin(), a.end());

        vector<ll> pref(m + 1, 0);
        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        ll ans = 0;

        for (int i = 0; i < m; i++) {
            ll need = n - a[i];

            int pos = lower_bound(a.begin(), a.end(), need) - a.begin();

            ll cnt = m - pos;
            ll sumAj = pref[m] - pref[pos];

            ans += cnt * (a[i] - n + 1) + sumAj;

            if (a[i] >= need) {
                ans -= (2 * a[i] - n + 1);
            }
        }

        cout << ans << '\n';

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

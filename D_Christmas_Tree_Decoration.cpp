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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

ll factorials[200005]; 
const int MOD = 998244353;

void precompute(int n) {
    factorials[0] = 1;
    for (int i=1; i<=n; i++) factorials[i] = (factorials[i - 1]*i)%MOD;
}

ll power(ll base, ll exp) {
    ll res=1;
    base %= MOD;
    while (exp>0) {
        if (exp%2 ==1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll nCr(int n, int r) {
    if (r<0 || r>n) return 0;
    ll num = factorials[n];
    ll den = (modInverse(factorials[r])*modInverse(factorials[n - r]))%MOD;
    return (num * den)%MOD;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    ll totalDec = 0;
    for(int i = 0; i<=n; i++){
        cin>>a[i];
        totalDec += a[i];
    }

    ll q = totalDec/n;
    int r = totalDec%n;

    ll demand0 = 0;
    int needCnt = 0;
    for (int i=1; i<=n; i++) {
        demand0 += max(0LL, q - a[i]);
        if (a[i] <= q) needCnt++;
    }

    ll K = a[0]-demand0;
    if (K<0) {
        cout<<0<<endl;
        return;
    }

    ll ans = 0;
    for (int k = 0; k <= min(r, needCnt); k++) {
        if (k <= K) {  
            ll ways = nCr(needCnt, k); 
            ways = (ways*nCr(n-needCnt, r-k))%MOD;
            ways = (ways*factorials[r])%MOD;
            ways = (ways*factorials[n-r])%MOD;
            ans = (ans+ways)%MOD;
        }
    }

    cout<<ans<<endl;
    // Output

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute(200000);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

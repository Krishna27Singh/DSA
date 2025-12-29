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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    ll n, k, q; cin >> n >> k >> q;
        vector<ll> a(n + 1, 0);
 
        vector<ll> mn(n + 1, 0), mx(n + 1, 0);
        while (q--) {
            ll c, l, r; cin >> c >> l >> r;
            for (ll i = l; i <= r; i++) {
                if (c == 1) mn[i] = 1;
                else mx[i] = 1;
            }
        }
 
        for (ll i = 1; i <= n; i++) {
            if (mn[i] == 1 && mx[i] == 1) a[i] = k + 1;
            else if (mx[i] == 1) a[i] = i % k;
            else a[i] = k;
        }
 
        for (ll i = 1; i <= n; i++) cout << a[i] << ' ';
        cout <<endl;

    // Output
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

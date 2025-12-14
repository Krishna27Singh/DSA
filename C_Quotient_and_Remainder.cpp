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
        int n; ll k; cin>>n >> k;
        vector<ll> q(n);
        for (int i = 0; i < n; ++i) cin >> q[i];
        vector<ll> r(n);
        for (int i = 0; i < n; ++i) cin>>r[i];

        vector<ll> Ls;
        Ls.reserve(n);
        for (int i = 0; i < n; ++i) {
            ll a = q[i];
            if (k < a) {
                Ls.push_back(-1); 
            } else {
                ll L = (k - a) / (a + 1);
                Ls.push_back(L);
            }
        }

        sort(Ls.begin(), Ls.end());
        sort(r.begin(), r.end());

        multiset<ll> available;    
        int idx = 0;             
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            ll L = Ls[i];
            if (L < 1) {
                continue;
            }
            while (idx<n&&r[idx] <= L) {
                available.insert(r[idx]);
                idx++;
            }
            if (!available.empty()) {
                auto it = prev(available.end());
                available.erase(it);
                ans++;
            }
        }

        // long long ans = 0;
        // for (int i = 0; i<n; i++) {
        //     ll Ymax = k/q[i];
        //     if (Ymax == 0) continue;

        //     ll peak =(k + 1)/(q[i] + 1);
        //     if (peak > Ymax) peak = Ymax;
        //     ll L1=0;
        //     ll R1=max(0LL, peak - 1);

        //     auto it = r.lower_bound(L1);
        //     bool matched = false;

        //     if (it!=r.end() && *it <= R1) {
        //         r.erase(it);
        //         ans++;
        //         matched = true;
        //     }
        //     if (matched) continue;

        //     if (peak < Ymax) {
        //         ll L2 = max(0LL, k - q[i] * Ymax);
        //         ll R2 = max(0LL, k - q[i] * (peak + 1));
        //         it = r.lower_bound(L2);

        //         if (it != r.end() && *it <= R2) {
        //             r.erase(it);
        //             ans++;
        //         }
        //     }
        // }
        cout << ans <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

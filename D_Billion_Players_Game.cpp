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

bool feasible(ll t, ll S_l0, ll S_r0, ll D,
                vector<ll>& d, vector<ll>& pref, ll total_pref) {
    ll need1 = t - S_l0;
    ll need2 = t - S_r0;
    if (need1<=0 && need2<=0) return true;

    int m = d.size();

    for (int b = 0; b <= m; b++) {
        ll sum_small = pref[b];
        if (need1 > (ll)4e18) continue;
        ll target = total_pref - need1 - sum_small;
        int y;
        if (target < 0) y = -1;
        else {
            auto it = upper_bound(pref.begin(), pref.end(), target);
            y = int(it - pref.begin()) - 1;
        }

        int a_min;
        if (y < 0) a_min = m + 1; 
        else a_min = max(0, m - y);
        if (a_min > m - b) continue;
        int lo = 0, hi = m - b, best = -1;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            ll sum_largest = total_pref - pref[m - mid];
            ll f = (sum_largest - sum_small) + D * (b - mid);

            if (f >= need2) {
                best = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if (best >= a_min) return true;
    }

    return false;
}

void solve(){
    int n, l ,r; cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0 ;i<n; i++) cin>>a[i];

    ll S_l0=0, S_r0 = 0;
        vector<ll> middle;

        for (ll x:a) {
            if (x<l) {
                S_l0 += (l - x);
                S_r0 += (r - x);
            } else if (x > r) {
                S_l0 += (x - l);
                S_r0 += (x - r);
            } else {
                middle.push_back(x);
            }
        }

        int m=middle.size();
        ll D=r - l;

        vector<ll> d(m);
        for (int i = 0; i < m; i++) d[i] = middle[i] - l;
        sort(d.begin(), d.end());

        vector<ll> pref(m+1, 0);
        for (int i = 0; i < m; i++) pref[i+1] = pref[i] + d[i];
        ll total_pref = pref[m];

        ll low = -(ll)4e18, high = (ll)4e18;

        while (low<high) {
            ll mid=low +(high- low +1) / 2;
            if (feasible(mid, S_l0, S_r0, D, d, pref, total_pref))
                low = mid;
            else
                high = mid - 1;
        }
        cout<<low<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

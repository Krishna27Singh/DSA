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

void solve() {
        int n;
        int a[200005];
        map<int, int> cnt;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
 
        ll base = 0;
        vector<int> odd, even;
        for (auto [x, c] : cnt) {
            base += (ll)x * (c / 2);
            if (c % 2 == 1) {
                odd.push_back(x);
            } else if (c >= 2) {
                even.push_back(x);
            }
        }
 
        if (base == 0) {
            cout << 0 << '\n';
            return;
        }
 
        ll ans = 0;
        for (int x : odd) {
            if (2 * base > x) {
                ans = max(ans, 2 * base + x);
            }
        }
 
        assert(is_sorted(odd.begin(), odd.end()));
        for (int i = 1; i < (int)odd.size(); i++) {
            if (odd[i - 1] + 2 * base > odd[i]) {
                ans = max(ans, odd[i - 1] + 2 * base + odd[i]);
            }
        }
 
        for (int x : even) {
            if (base - x > 0) {
                ans = max(ans, 2 * base);
            }
        }
 
        cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

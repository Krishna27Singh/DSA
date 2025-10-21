#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Step 1: prefix maxima (after any number of op1)
        vector<ll> pref(n);
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = max(cur, a[i]);
            pref[i] = cur;
        }

        auto calc = [&](int startParity) -> ll {
            // startParity = 0 -> valleys at even indices (1-based odd)
            // startParity = 1 -> valleys at odd indices (1-based even)
            ll cost = 0;
            vector<ll> b = pref;

            for (int i = 0; i < n; ++i) {
                int left = i - 1;
                int right = i + 1;
                if ((i % 2) == startParity) {
                    // This index must be valley
                    ll leftVal = (left >= 0 ? b[left] : (ll)1e18);
                    ll rightVal = (right < n ? b[right] : (ll)1e18);
                    ll minNbr = min(leftVal, rightVal);
                    ll target = minNbr - 1;
                    if (b[i] > target) {
                        cost += b[i] - target;
                        b[i] = target;
                    }
                }
            }
            return cost;
        };

        ll ans = min(calc(0), calc(1));
        cout << ans << "\n";
    }

    return 0;
}

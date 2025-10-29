#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        ll x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        auto possible = [&](ll d)->bool{
            if (d == 0) return (x + 1) >= k; // all positions allowed
            // forbidden intervals are [ai-(d-1), ai+(d-1)]
            vector<pair<ll,ll>> segs;
            segs.reserve(n);
            ll r = d - 1;
            for (int i = 0; i < n; ++i) {
                ll L = a[i] - r;
                ll R = a[i] + r;
                if (R < 0 || L > x) continue;
                L = max(L, 0LL);
                R = min(R, x);
                segs.emplace_back(L, R);
            }
            if (segs.empty()) return (x+1) >= k;
            sort(segs.begin(), segs.end());
            ll covered = 0;
            ll curL = segs[0].first, curR = segs[0].second;
            for (size_t i = 1; i < segs.size(); ++i) {
                if (segs[i].first > curR + 1) {
                    covered += (curR - curL + 1);
                    curL = segs[i].first;
                    curR = segs[i].second;
                } else {
                    curR = max(curR, segs[i].second);
                }
            }
            covered += (curR - curL + 1);
            ll allowed = (x + 1) - covered;
            return allowed >= k;
        };

        // binary search max d
        ll lo = 0, hi = x + 1; // d in [0, x+1]
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (possible(mid)) lo = mid;
            else hi = mid - 1;
        }
        ll bestD = lo;

        // construct k positions for bestD
        vector<pair<ll,ll>> forb;
        if (bestD > 0) {
            ll r = bestD - 1;
            for (int i = 0; i < n; ++i) {
                ll L = a[i] - r;
                ll R = a[i] + r;
                if (R < 0 || L > x) continue;
                L = max(L, 0LL);
                R = min(R, x);
                forb.emplace_back(L, R);
            }
            sort(forb.begin(), forb.end());
            // merge
            vector<pair<ll,ll>> merged;
            for (auto &p : forb) {
                if (merged.empty() || p.first > merged.back().second + 1) merged.push_back(p);
                else merged.back().second = max(merged.back().second, p.second);
            }
            // iterate gaps and pick positions
            vector<ll> ans;
            ll cur = 0;
            for (auto &seg : merged) {
                if (cur <= seg.first - 1) {
                    for (ll pos = cur; pos <= seg.first - 1 && (int)ans.size() < k; ++pos) ans.push_back(pos);
                }
                cur = seg.second + 1;
                if ((int)ans.size() == k) break;
            }
            for (ll pos = cur; pos <= x && (int)ans.size() < k; ++pos) ans.push_back(pos);

            // If bestD==0 or for some reason we don't have enough (shouldn't happen), fill from 0 upward
            if ((int)ans.size() < k) {
                for (ll pos = 0; pos <= x && (int)ans.size() < k; ++pos) {
                    // avoid duplicates
                    if (!binary_search(ans.begin(), ans.end(), pos)) ans.push_back(pos);
                }
            }

            // print exactly k positions
            for (int i = 0; i < k; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        } else {
            // bestD == 0: any k distinct in [0,x]
            for (int i = 0; i < k; ++i) {
                if (i) cout << ' ';
                cout << i; // i <= x because k <= x+1 by constraints
            }
            cout << '\n';
        }
    }
    return 0;
}

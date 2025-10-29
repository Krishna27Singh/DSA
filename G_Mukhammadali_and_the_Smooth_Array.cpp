#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickMax {
    int n;
    vector<ll> bit;
    FenwickMax(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0); // 0 is safe baseline since costs are positive
    }
    // set bit[idx] = max(bit[idx], val) (1-indexed)
    void update(int idx, ll val){
        for(; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
    // query max on prefix [1..idx]
    ll query(int idx){
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n), c(n);
        for(int i=0;i<n;++i) cin >> a[i];
        ll sumC = 0;
        for(int i=0;i<n;++i){ cin >> c[i]; sumC += c[i]; }

        // coordinate compress a
        vector<ll> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = (int)vals.size();

        auto pos = [&](ll x){
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1; // 1-indexed
        };

        FenwickMax fw(m);
        for(int i=0;i<n;++i){
            int p = pos(a[i]);
            ll bestPrev = fw.query(p); // non-decreasing allows <= a[i]
            ll dp = bestPrev + c[i];
            fw.update(p, dp);
        }
        ll maxKeep = fw.query(m);
        ll answer = sumC - maxKeep;
        cout << answer << '\n';
    }
    return 0;
}

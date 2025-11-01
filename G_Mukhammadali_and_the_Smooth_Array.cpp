#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct solve {
    int n;
    vector<ll> bit;
    solve(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0); 
    }

    void update(int idx, ll val){
        for(; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
    
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

        
        vector<ll> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = (int)vals.size();

        auto pos = [&](ll x){
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1; 
        };

        solve fw(m);
        for(int i=0;i<n;++i){
            int p = pos(a[i]);
            ll best_prev = fw.query(p); 
            
            ll dp = best_prev + c[i];
            fw.update(p, dp);
        }
        ll maxKeep = fw.query(m);
        ll answer = sumC - maxKeep;
        cout << answer <<endl;
    }
    return 0;
}


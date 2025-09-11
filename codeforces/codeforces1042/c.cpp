#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> S(n), T(n);
        unordered_map<ll,ll> fS, fT;
        fS.reserve(n*2); fT.reserve(n*2);

        for (int i = 0; i < n; ++i) { cin >> S[i]; fS[S[i]]++; }
        for (int i = 0; i < n; ++i) { cin >> T[i]; fT[T[i]]++; }

        for (auto &p : fS) {
            ll val = p.first;
            auto it = fT.find(val);
            if (it != fT.end()) {
                ll common = min(p.second, it->second);
                p.second -= common;
                it->second -= common;
            }
        }

        unordered_map<ll,ll> remS, remT;
        remS.reserve(fS.size()*2); remT.reserve(fT.size()*2);
        for (auto &p : fS) if (p.second > 0) remS[p.first % k] += p.second;
        for (auto &p : fT) if (p.second > 0) remT[p.first % k] += p.second;

        bool ok = true;                             
        unordered_set<ll> checked;
        checked.reserve(remS.size()*2 + remT.size()*2);

        for (auto &p : remS) {
            ll r = p.first;
            if (checked.count(r)) continue;
            ll s = (k - r) % k;
            ll sumS = remS[r] + remS[s];
            ll sumT = remT[r] + remT[s];
            if (sumS != sumT) { ok = false; break; }
            checked.insert(r); checked.insert(s);
        }
        if (ok) {
            for (auto &p : remT) {
                ll r = p.first;
                if (checked.count(r)) continue;
                ll s = (k - r) % k;
                ll sumS = remS[r] + remS[s];
                ll sumT = remT[r] + remT[s];
                if (sumS != sumT) { ok = false; break; }
                checked.insert(r); checked.insert(s);
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

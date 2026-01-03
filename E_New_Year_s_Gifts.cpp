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

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vector<ll> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    for(int i = 0; i<n; i++) cin>>x[i]>>y[i]>>z[i];

    ll temp = 0;
    for(auto i: y) temp += i;
    k -= temp;
    for(int i = 0; i<n; i++) z[i] -= y[i];

    ll cnt = 0;

    vector<pair<ll, ll>> newZ;
    for(int i = 0; i<n; i++){
        auto myPair = make_pair(z[i], i);
        newZ.push_back(myPair);
    }
    sort(newZ.begin(), newZ.end());
    reverse(newZ.begin(), newZ.end());

    multiset<ll> s;
    for(int i = 0; i<m; i++) s.insert(a[i]);
    vector<bool> done(n, false);

    for(int i = 0; i<n; i++){
        ll beautyNeeded = x[newZ[i].second];
        auto it = s.lower_bound(beautyNeeded);
        if(it != s.end()){
            cnt++;
            done[newZ[i].second] = true;
            s.erase(it);
        }
    }

    reverse(newZ.begin(), newZ.end());

    int it = 0;
    while(it < n){
    if(done[newZ[it].second]){
        it++;
        continue;
    }
    if(k < newZ[it].first) break;
    k -= newZ[it].first;
    cnt++;
    it++;
    }


    cout<<cnt<<endl;

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

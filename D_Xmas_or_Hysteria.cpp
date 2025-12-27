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
    ll n,m;
    cin >> n >> m;
    m = n - m; 
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
 
    if(m < (n + 1) / 2) {
        cout << -1 << endl;
        return;
    }
    vector<pair<ll,ll>> ans;
 
    for(int i = n-2; i >= 0; i -= 2) {
        if(i + (n - i) / 2 == m) {
            for(int j = 0; j < i; j++) {
                ans.push_back({v[j].second,v[j+1].second});
            }
            for(int j = n-1; j >= i; j -= 2) {
                ans.push_back({v[j].second, v[j-1].second});
            }
            break;
        }
    }
 
    if(ans.size() == 0) {
        assert(m == n);
        ll sum = 0;
        for(int i = 0; i < n-1; i++) {
            sum += v[i].first;
        }
        if(sum < v.back().first) {
            cout << -1 << endl;
            return;
        }
        sum = 0;
        int p1;
        for(p1 = n-2; sum < v.back().first; p1--) {
            sum += v[p1].first;
        }
        for(int i = 0; i <= p1; i++) {
            ans.push_back({v[i].second,v[i+1].second});
        }
        for(int i = p1 + 1; i < n-1; i++) {
            ans.push_back({v[i].second, v.back().second});
        }
    }
 
    cout << ans.size() << endl;
    for(auto [x,y] : ans) {
        cout << x +1  << ' ' << y + 1 << endl;
    }

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

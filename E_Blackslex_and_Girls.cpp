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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    
    string s;
    cin >> s;
    s = '.'+s;
    
    ll p[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    if (accumulate(p+1, p+n+1, 0LL) > x+y) {
        cout << "NO\n";
        return;
    }
    
    if (s == "." + string(n, '0') || s == "." + string(n, '1')) {
        if (s == "." + string(n, '1')) {
            swap(x, y);
        }
        
        ll x_need = 0;
        for (int i = 1; i <= n; i++) {
            x_need += p[i]/2 + 1;
        }
        
        if (x < x_need || x < y+n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
        return;
    }
    
    ll x_need = 0, y_need = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            x_need += p[i]/2 + 1;
        } else {
            y_need += p[i]/2 + 1;
        }
    }
    if (x >= x_need && y >= y_need) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

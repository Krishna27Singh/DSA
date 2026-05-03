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
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************
72 24 3 3 3 3
3 3 3 6 12 144                                

1 2 3
4 5 6

2
12 11
9 10


*/

void solve(){
    int n; cin >> n;
    vector<ll> p(n), s(n);
    for(auto &x: p) cin >> x;
    for(auto &x: s) cin >> x;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        a[i] = gcd(p[i], s[i]);
    }
    for(auto i: a) cout << i << " ";
    cout << "\n";

    // check prefix gcd
    ll cur = a[0];
    if(cur != p[0]){
        cout << "NO\n";
        return;
    }

    for(int i = 1; i < n; i++){
        cur = gcd(cur, a[i]);
        if(cur != p[i]){
            cout << "NO\n";
            return;
        }
    }

    // check suffix gcd
    cur = a[n-1];
    if(cur != s[n-1]){
        cout << "NO\n";
        return;
    }

    for(int i = n-2; i >= 0; i--){
        cur = gcd(cur, a[i]);
        if(cur != s[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

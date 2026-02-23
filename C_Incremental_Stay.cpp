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
atmost 1 person can pass through the door at a time

stay time = exit time - entrance time

museum was closed at second 0

atmost k people can stay in the museum simultaneously
k = 1 -> n
find the sum of maximum possible stay time for all the people for each k


*/

void solve(){
    ll n; cin >> n;
        vector<ll> v;
        for (ll i = 0; i < 2 * n; i++) {
            ll x; cin >> x; v.pb(x);
        }
 
        vector<ll> ans(n + 3, 0);
        for (ll i = 0; i < 2 * n; i += 2) ans[1] -= v[i];
        for (ll i = 1; i < 2 * n; i += 2) {
            ans[1] += v[i]; ans[2] -= v[i];
        }
        for (ll i = 2; i < 2 * n; i += 2) ans[2] += v[i];
        ans[2] += 2 * v.back() - v[0];
 
        for (ll i = 3; i <= n; i++) {
            ans[i] = ans[i - 2] + 2 * (v[(ll)v.size() - i + 1] - v[i - 2]);
        }
 
        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    // Output


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

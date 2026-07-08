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
I need to know either thhe set or unset bit in each number from a1 to a 2^k + 1


*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    char g;
    for (int i = 0; i < n; ++i) {
        cin >> g;
        a[i] = g - '0';
    }
    for (int i = 0; i < n; ++i) {
        cin >> g;
        b[i] = g - '0';
    }
    vector<int> c(4);
    for (int i = 0; i < n; ++i) {
        int x = 2 * a[i] + b[i];
        c[x]++;
    }
        
    if (k % 2) {
        long long p = 0, q = 0, r = 0;
        p = c[0] + c[1];
        q = c[0] + c[3];
        r = c[0] + c[2];
        cout << (((1ll << k) + 1) / 3) * (p * (n-p) + q * (n - q) + r * (n - r)) << "\n";
    } else {
        long long p = 0, q = 0, r = 0;
        p = c[0] + c[1];
        q = c[0] + c[2];
        r = c[0] + c[3];
        cout << (((1ll << k) + 1) / 3) * (p * (n-p) + q * (n - q) + r * (n - r)) + p * (n - p) + q * (n - q) << "\n";
    }
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

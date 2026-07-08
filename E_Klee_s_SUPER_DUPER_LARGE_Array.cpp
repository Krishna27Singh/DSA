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

*/

long long pref(long long i, long long k) {
    return i * k + (i * (i - 1)) / 2;
}

void solve() {
    long long n, k;
    cin >> n >> k;

    long long t = pref(n, k);

    long double b = 2.0L * k - 1.0L;
    long double c = (long double)t;
    
    long double D = b * b + 4.0L * c;

    long double i = (-b + sqrtl(D)) / 2.0L;
    
    long long idx = (long long)i;

    long long del = -1;

    long long s = max(1LL, idx - 1);
    long long e = min(n, idx + 2);

    for (long long i = s; i <= e; ++i) {
        long long curr = abs(t - 2 * pref(i, k));
        
        if (del == -1 || curr < del) {
            del = curr;
        }
    }

    cout << del << "\n";
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

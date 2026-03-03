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

const int INF = 1000000005;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************
penalty -> number of indices such that b[i] < b[i+1]
given a -> split into two subsequences s and t
find minimum val of p(s) + p(t)

f(i) -> total penalty of the array till index i ! 
now we do it recursively
if(i == n) return 
*/

/*
****************************************** Testing ****************************************************

*/

const int MAXN = 200005;

int n;
int a[MAXN];

void solve(){
    cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int t1 = INF, t2 = INF;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t1 > t2) {
                swap(t1, t2);
            }
            if (a[i] <= t1) {
                t1 = a[i];
            } else if (a[i] <= t2) {
                t2 = a[i];
            } else {
                t1 = a[i];
                ans++;
            }
        }
        cout << ans << '\n';



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

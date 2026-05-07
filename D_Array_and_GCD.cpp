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
const int N = 6e6;
vector<int> p, ip(N, 1);


void solve(){
    int n; cin>>n;
    vector<int> a(n);
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    long long suma = 0, sump = 0;
    for (int i = 0; i < n; ++i) {
      suma += a[i];
      sump += p[i];
      if (suma >= sump) ans = i + 1;
    }
    cout << n - ans << endl;
    

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 2; i < N; ++i) {
        if (!ip[i]) continue;
            p.push_back(i);
            for (int j = i; j < N; j += i) {
            ip[j] = 0;
        }
    }
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

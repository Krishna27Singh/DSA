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
maximum possible number of cubes that move

operation -> remove one cube from any column 

for a particular ai, I wanna find out how many ai's are there that are on the left of ai and are >= ai
how can this be done?
1. sort the array and then for each ai find out how many ai's are there that are on the left of ai and are >= ai -> O(nlogn)
2. use fenwick tree -> O(nlog(maxAi))
3. use segment tree -> O(nlog(maxAi))                           
*/

/*
****************************************** Testing ****************************************************

*/


void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> mini(n);

    ll mn = INT_MAX;
    ll cnt = 0;
    for(int i = n-1; i>=0; i--){
        mn = min(mn, a[i]);
        mini[i] = mn;
        cnt += a[i] - mn;
    }

    unordered_map<ll, ll> mpp;
    for(auto i: mini) mpp[i]++;

    ll mx = 0;
    for(auto i: mpp) mx = max(mx, i.second);

    cnt += mx;
    cout<<cnt-1<<endl;
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

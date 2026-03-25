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
initially x = 0
1) ai = ai + x; and x++ -> only once for each ai -> max n times
2) x++;

each ai%k == 0

minimum moves ?
*/

/*
****************************************** Testing ****************************************************
2 2 5 6 6 -> 5 + 6 = 11 ?

4 3
1 2 1 3

k = 3
x += 1
a1 += x
x += 1
a0 += x
a2 += x

4 3
1 2 1 3

2 1 2 0 

1 2 2


10 6
8 7 1 8 3 7 5 10

1 2 3 3 4 4 4 5 5 5 


*/

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    multiset<ll> ms;
    for(int i = 0; i<n; i++){
        if(a[i]%k) ms.insert(k - (a[i]%k));
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

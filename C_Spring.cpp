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
m days 
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll a, b, c, m; cin>>a>>b>>c>>m;

    // a, 2a, 3a, ..
    // b, 2b, 3b, ...
    // c, 2c, 3c, ...
    // gonna store the values of (y*b) in a map mpp such that (x*a) = (y*b) ! 
    // then gonna check the values of (y*b) such that (y*b) = (z*c) and if (y*b) exist in mpp

    // if x*a == y*b -? alice += 3 and bob += 3
    // if y*b == z*c -> bob += 3 and carol += 3
    // if x*a == z*c and x-> alice += 3 and carol += 3
    // if y*b == z*c and y*c also exist in mpp then alice += 2 bob += 2 carol += 2

    ll na = m/a;
    ll nb = m/b;
    ll nc = m/c;

    ll ab = m/lcm(a, b);
    ll bc = m/lcm(b, c);
    ll ac = m/lcm(a, c);
    ll abc = m/lcm(a, lcm(b, c));

    ll alice = 6*na - 3*ab - 3*ac + 2*abc;
    ll bob = 6*nb - 3*ab - 3*bc + 2*abc;
    ll carol = 6*nc - 3*ac - 3*bc + 2*abc;

    cout<<alice<<" "<<bob<<" "<<carol<<endl;    

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

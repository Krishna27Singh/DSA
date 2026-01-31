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

void solve(){
    int x, y; cin>>x>>y;

    int msb = max((31 - __builtin_clz(x)), (31 - __builtin_clz(y)));
    int q = 0;

    int q1 = 0;
    // p = x
    for(int i = 0; i <= msb; i++){
        if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1){
            q1 |= (1 << i);
        }
    }

    int q2 = 0;
    // q = y
    for(int i = 0; i <= msb; i++){
        if(((y >> i) & 1) == 0 && ((x >> i) & 1) == 1){
            q2 |= (1 << i);
        }
    }

    if(q1 > q2){
        cout<<x<<" "<<q1<<endl;
        return;
    }
    cout<<q2<<" "<<y<<endl;

    // cout<<p<<" "<<q<<endl;

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

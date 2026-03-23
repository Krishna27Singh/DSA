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
manhatten distance is simply = abs(r1 - r2) + abs(c1 - c2)
sum of manhattan distances between each pair of cells of the same color ?

{(r1, c1), (r2, c2), (r3, c3),,, (rn, cn)}
abs(r1-r2) + abs(r1-r2) + .. + abs(r1-rn)
abs(r2-r3) + abs(r3-r4) +.. + abs(r2-rn)
abs(r3-r4) + abs(r4- r5) +.. abs(r3-rn)
abs(rn-1 - rn)
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> c(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) cin>>c[i][j];
    }

    unordered_map<int, vector<int>> mppr;
    unordered_map<int, vector<int>> mppc;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            mppr[c[i][j]].pb(i);
            mppc[c[i][j]].pb(j);
        }
    }

    ll ans = 0;
    for(auto [clr, rows] : mppr){
        sort(all(rows));
        ll prefix = 0;
        int l = rows.size();
        for(int i = 0; i<l; i++){
            ans += 1LL * rows[i] * i - prefix;
            prefix += rows[i];
        }
    }
    for(auto [clr, cols] : mppc){
        sort(all(cols));
        ll prefix = 0;
        int l = cols.size();
        for(int i = 0; i<l; i++){
            ans += 1LL * cols[i] * i - prefix;
            prefix += cols[i];
        }
    }

    cout<<ans<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int tc; cin >> tc;
    solve();
    return 0;
}

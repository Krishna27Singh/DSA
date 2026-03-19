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

void solve(){
    int n, m; cin>>n>>m;
    unordered_map<int, int> mpp;
    for(int i = 0; i<m; i++){
        // x y (x < y)
        int x, y; cin>>x>>y;
        if(y>x) swap(x, y);
        mpp[x] = y;
    }

    vector<int> segs;
    for(int i = 1; i<=n; i++){
        if(mpp.find(i) != mpp.end()) i = mpp[i];
        else{
            int left = i;
            while(i<=n && mpp[i] == 0) i++;
            int right = i;
            i--;
            segs.pb(right-left);
        }
    }

    int ans = 0;
    for(auto i: segs) ans += 

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

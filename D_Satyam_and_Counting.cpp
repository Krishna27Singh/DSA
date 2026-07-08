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
    ll n; cin>>n;
    vector<pair<ll, ll>> pairs(n);
    for(int i = 0; i<n; i++){
        cin>>pairs[i].first>>pairs[i].second;
    }

    ll u = 0;
    ll l = 0;

    for(auto [x,y] : pairs){
        if(y == 1) u++;
        else l++;
    }

    unordered_map<int, vector<int>> mpp;

    for(auto [x,y] : pairs){
        mpp[x].pb(y);
    }


    ll cnt = 0;
    for(int x = 0; x<=n; x++){
        if(mpp[x].size() == 2){
            cnt += (l-1);
            cnt += (u-1);
        }
    }

    for(int x = 0; x<=n-2; x++){
        // case 1: 0 1 0
        if((mpp[x].size() == 1 && mpp[x][0] == 0 || mpp[x].size() == 2 && mpp[x][1] == 0 || mpp[x].size() == 2 && mpp[x][0] == 0)
          && (mpp[x+1].size() == 1 && mpp[x+1][0] == 1 || mpp[x+1].size() == 2 && mpp[x+1][1] == 1 || mpp[x+1].size() == 2 && mpp[x+1][0] == 1)
          && (mpp[x+2].size() == 1 && mpp[x+2][0] == 0 || mpp[x+2].size() == 2 && mpp[x+2][1] == 0 || mpp[x+2].size() == 2 && mpp[x+2][0] == 0)){
            cnt++;
        }

        // case 2: 1 0 1
        if((mpp[x].size() == 1 && mpp[x][0] == 1 || mpp[x].size() == 2 && mpp[x][1] == 1 || mpp[x].size() == 2 && mpp[x][0] == 1)
          && (mpp[x+1].size() == 1 && mpp[x+1][0] == 0 || mpp[x+1].size() == 2 && mpp[x+1][1] == 0 || mpp[x+1].size() == 2 && mpp[x+1][0] == 0)
          && (mpp[x+2].size() == 1 && mpp[x+2][0] == 1 || mpp[x+2].size() == 2 && mpp[x+2][1] == 1 || mpp[x+2].size() == 2 && mpp[x+2][0] == 1)){
            cnt++;
          }
    }

    // Output
    cout << cnt << "\n";


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

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
how to get rid of the intersection
just traverse in ascending order ... thats it !
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll cntb, cntg, k; cin>>cntb>>cntg>>k;
    vector<ll> b(k);
    for(int i = 0; i<k; i++) cin>>b[i];
    vector<ll> g(k);
    for(int i = 0; i<k; i++) cin>>g[i];

    ll ans = 0;

    unordered_map<ll, ll> mppb;
    for(int i = 0; i<k; i++) mppb[b[i]]++;
    unordered_map<ll, ll> mppg;
    for(int i = 0; i<k; i++) mppg[g[i]]++;

    vector<pair<ll, ll>> bg;
    for(int i = 0; i<k; i++) bg.pb(mp(b[i], g[i]));

    // for(auto i: bg) cout<<i.first<<" "<<i.second<<endl;
    // for(auto i: mppb) cout<<i.first<<" "<<i.second<<endl;
    // cout<<endl;
    // for(auto i: mppg) cout<<i.first<<" "<<i.second<<endl;
    

    for(int i = 0; i<k; i++){
        auto currBoy = bg[i].first;
        auto currGirl = bg[i].second;
        ll cnt = k - i - mppb[currBoy] - mppg[currGirl] + 1;
        // cout<<"cnt: "<<cnt<<endl;
        if(cnt > 0) ans += cnt;

        mppb[bg[i].first]--;  
        mppg[bg[i].second]--; 
    }

    cout<<ans<<endl;

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

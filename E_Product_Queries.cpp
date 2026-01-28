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
    ll n; cin>>n;
    set<ll> s;
    for(int i = 0; i<n; i++){
        ll x; cin>>x;
        s.insert(x);
    }

    vector<ll> dp(n+1, INF);
    for(ll product = 1; product<=n; product++){
        if(s.find(product) != s.end()){
            dp[product] = 1;
        }
    }

    for(ll product = 1; product<=n; product++){
        if(dp[product] == 1) continue;
        for(ll factor = 2; factor*factor <= product; factor++){
            if(product&factor == 0){
                ll otherFactor = product/factor;
                dp[product] = min(dp[product], 1 + dp[product/factor]);
                dp[product] = min(dp[product], 1 + dp[product/otherFactor]);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        if(dp[i] == INF) cout<<-1<<" ";
        else cout<<dp[i]<<" ";
    }
    cout<<endl;

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

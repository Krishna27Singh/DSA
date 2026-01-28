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
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    vector<ll> prefix(n);
    prefix[0] = b[0];
    for(int i = 1; i<n; i++){
        prefix[i] = prefix[i-1] + b[i];
    }
    for(int i = n-1; i>=0; i--){
        ll x = a[i];
        ll swords = n - i;

        ll idx = upper_bound(prefix.begin(), prefix.end(), swords) - prefix.begin();
        // cout<<"x: "<<x<<endl;
        // cout<<"idx: "<<idx<<endl;
        // cout<<"swords: "<<swords<<endl;
        ans = max(ans, x*(idx));
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

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
need to perform k operations
choose two integers ai and aj and append |ai-aj| to a 


*/

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    if(k>=3){
        cout<<0<<endl;
        return;
    }

    if(k == 1){
        sort(all(a));
        ll ans = a[0];
        for(int i = 0; i<n-1; i++) ans = min(ans, abs(a[i]-a[i+1]));
        cout<<ans<<endl;
        return;
    }

    sort(all(a));
    vector<ll> possible;
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++) possible.pb(abs(a[i]-a[j]));
    }
    ll ans = LLONG_MAX;
    for(auto num : possible){
        auto it = lower_bound(all(a), num);
        if(it != a.end()) ans = min(ans, abs(*it - num));
        if(it != a.begin()){
            --it;
            ans = min(ans, abs(*it - num));
        }
    }
    for(auto i: possible) ans = min(ans, i);
    for(auto i: a) ans = min(ans, i);
    cout<<ans<<endl;
    return;
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

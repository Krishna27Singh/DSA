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
f(a) -> number of subarrays of a such that product is multiple of 6
reorder a such that f(a) is minimum
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> ans;
    vector<int> vis(n, false);

    for(int i = 0; i<n; i++){
        if(a[i]%6 == 0){
            ans.pb(a[i]);
            vis[i] = true;
        }
    }

    for(int i = 0; i<n; i++){
        if(a[i]%3 == 0 && !vis[i]){
            ans.pb(a[i]);
            vis[i] = true;
        }
    }

    for(int i = 0; i<n; i++){
        if(a[i]%2 != 0 && !vis[i]){
            ans.pb(a[i]);
            vis[i] = true;
        }
    }

    for(int i = 0; i<n; i++){
        if(a[i]%2 == 0 && !vis[i]){
            ans.pb(a[i]);
            vis[i] = true;
        }
    }
    
    for(auto i: ans) cout<<i<<" ";
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

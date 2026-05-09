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

1 2 2 
*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    map<int, vector<int>> mpp;
    for(int i = 0; i<n; i++) mpp[a[i]].pb(i);

    vector<int> vis(n+1, 0); 
    int ans = 0;

    for(auto it = mpp.rbegin(); it != mpp.rend(); it++){
        // cout<<it->first<<" "<<it->second.size()<<endl;
        auto idcs = it->second;
        vector<int> prev;
        int l = idcs.size();
        for(int i = 0; i<l; i++){
            int idx = idcs[i];
            if((idx - 1 >= 0 && vis[idx-1] == 1) || (idx + 1 < n && vis[idx+1] == 1)){
                vis[idx] = 1;
                for(auto j: prev) vis[j] = 1;
                prev.clear();
                continue;
            }
            if(i < l-1 && idcs[i+1] == idx+1){
                prev.pb(idx);
            }
            else{
                ans++;
                vis[idx] = 1;
                for(auto j: prev) vis[j] = 1;
                prev.clear();
            }
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
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

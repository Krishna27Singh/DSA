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
x and 7- x lie on opposite side of the cube

we need to check the extent of problem
cnt = number of extent / 2
*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> extend;
    for(int i = 0; i<n-1; i++){
        if(a[i] == a[i+1] || a[i+1] == 7 - a[i]){
            // cout<<"i "<<i<<endl;
            int cnt = 1;
            while(i+1 < n && (a[i] == a[i+1] || a[i+1] == 7 - a[i])){
                cnt++;
                i++;
            }
            extend.pb(cnt);
        }
    }
    // for(auto i: extend) cout<<i<<" ";
    // cout<<endl;
    
    int ans = 0;
    for(auto i: extend) ans += i/2;

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

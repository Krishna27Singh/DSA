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
    int n, x, y; cin>>n>>x>>y;

    // vector<pair<int, int>> modu;
    // for(int i = 0; i<n; i++){
    //     int temp; cin>>temp;
    //     int modulo = temp%x;
    //     modu.pb(mp(modulo, temp));
    // }
    // sort(all(modu));
    // // for(auto i: modu) cout<<i.first<<" "<<i.second<<endl;
    // // cout<<endl;

    // int tax = x - y;
    // int ans = 0;
    // for(int i = 0; i<n-1; i++){
    //     int temp = modu[i].second - modu[i].first;
    //     ans += temp - (temp/x)*tax;
    // }

    // cout<<ans+modu[n-1].second<<endl;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long S_all = 0;
        for (int i = 0; i < n; i++) {
            S_all += a[i] / x;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long Si = S_all - (a[i] / x);
            long long final_amount = a[i] + Si * y;
            ans = max(ans, final_amount);
        }

        cout << ans <<endl;



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

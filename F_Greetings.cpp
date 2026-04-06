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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

|1  |2  |1 |2    |3     |4  |3   |5   |4   |5 

*/

/*
****************************************** Testing ****************************************************
-5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10        100
    1     2          3 3 2 4 4 5 1  5               
*/

void solve(){
    // int n; cin>>n;
    // vector<int> a(n);
    // vector<int> b(n);
    // vector<int> compression;
    // for(int i = 0; i<n; i++){
    //     cin>>a[i]>>b[i];
    //     compression.pb(a[i]);
    //     compression.pb(b[i]);   
    // }
    // sort(all(compression));

    // vector<int> positions(2*n+1); 
    // unordered_map<int, int> mpp;
    // for(int i = 1; i<=2*n; i++){
    //     mpp[compression[i-1]] = i;
    // }

    // for(int i = 0; i<n; i++){
    //     positions[mpp[a[i]]] = i+1;
    //     positions[mpp[b[i]]] = i+1;
    // }

    // int ans = 0;
    // vector<vector<int>> groups(n+1);
    // for(int i = 1; i<=2*n; i++){
    //     groups[positions[i]].pb(i);
    // }
    // for(int i = 1; i<=n; i++){
    //     int l = groups[i][0];
    //     int r = groups[i][1];
    //     vector<bool> vis(2*n+1, false);
    //     for(int j = l; j<=r; j++){
    //         if(vis[positions[j]]) ans++;
    //         vis[positions[j]] = true;
    //     }
    //     ans--;
    // }
    // cout<<ans<<endl;

    int n;
				cin >> n;
				vector<pair<int, int>> vec(n); 
				for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;

				sort(vec.begin(), vec.end());

				Oset st;          
				long long ans = 0; 

				for (int i = 0; i < n; i++) {
						ans += i - st.order_of_key(vec[i].second);
						st.insert(vec[i].second); 
				}

				cout << ans << '\n';



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

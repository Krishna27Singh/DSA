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
lets take the common sum as 0
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll n, m; cin>>n>>m;
    string s; cin>>s;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    int r = 0, c = 0;
    
    for (char step : s) {
        if (step == 'D') {
            ll current_sum = 0;
            for (int j = 0; j < m; j++) {
                current_sum += grid[r][j];
            }
            grid[r][c] = -current_sum;
            r++; 
        } else {
            ll current_sum = 0;
            for (int i = 0; i < n; i++) {
                current_sum += grid[i][c];
            }
            grid[r][c] = -current_sum;
            c++; 
        }
    }
    
    ll final_sum = 0;
    for (int j = 0; j < m; j++) {
        final_sum += grid[n-1][j];
    }
    grid[n-1][m-1] = -final_sum;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

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

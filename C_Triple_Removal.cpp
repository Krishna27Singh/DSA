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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> zeros(n + 1, 0);
    vector<int> ones(n + 1, 0);
    vector<int> same_adj(n, 0); 

    for(int i = 0; i < n; i++){
        zeros[i+1] = zeros[i] + (a[i] == 0);
        ones[i+1] = ones[i] + (a[i] == 1);
        
        if (i > 0) {
            same_adj[i] = same_adj[i-1] + (a[i] == a[i-1]);
        }
    }

    while(q--){
        int l, r; cin >> l >> r;
        l--; 
        r--;
        
        int cnt0 = zeros[r+1] - zeros[l];
        int cnt1 = ones[r+1] - ones[l];
        
        if((cnt0 % 3 != 0) || (cnt1 % 3 != 0)){
            cout << -1 << "\n";
            continue;
        }

        int triplets = cnt0 / 3 + cnt1 / 3;
        
        if (same_adj[r] - same_adj[l] == 0) {
            triplets++;
        }
        
        cout << triplets << "\n";
    }
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

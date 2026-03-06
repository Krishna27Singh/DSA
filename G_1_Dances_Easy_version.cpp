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
m = 1
reorder/or not elements
1 operation -> remove 1 element from a and b 
minimum ops req such that ai < bi for all remaining elements



*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, m; cin>>n>>m;
    // m == 1
    vector<int> a(n);
    a[0] = 1;
    for(int i = 1; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    int cnt = 0;
    sort(all(a)); sort(all(b));
    vector<bool> vis(n, false);
    int ptr = n-1;

    for(int i = n-1; i>=0; i--){
        // iterating b
        int bi = b[i];
        while(ptr >= 0){
            int ai = a[ptr];
            if(bi > ai){
                ptr--;
                cnt++;
                break;
            }
            else ptr--;
        }
        if(ptr < 0) break;
    }

    cout<<n-cnt<<endl;

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

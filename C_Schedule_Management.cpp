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

*/

bool check(int t, vector<int> &cnt, int n){
    ll fr = 0; ll need = 0;
    for(int i = 0; i<n; i++){
        if(t >= cnt[i]) fr += (t - cnt[i])/2;
        else need += cnt[i] - t;
    }
    return need <= fr;
}

void solve(){
    int n, m; cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i<m; i++){
        cin>>a[i];
        a[i]--;
    }

    vector<int> cnt(n, 0);
    for(int i = 0; i<m; i++) cnt[a[i]]++;

    int lo = 0;
    int hi = 2*m;
    int res = -1;
    while(lo <= hi){
        int m = lo + (hi - lo)/2;
        if(check(m, cnt, n)){
            res = m;
            hi = m-1;
        }
        else lo = m+1;
    }

    cout<<res<<endl;

    

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

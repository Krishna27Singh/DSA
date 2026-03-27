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
ai -> elevation of dirt in the column ai 

2 drains allowed 

2 drains we need to choose 
we have to choose a drain such that it is the bottom of between 2 peaks

do 2 loops for 2 drains ! 

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, h; cin>>n>>h;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> peaks;
    peaks.pb(-1);
    for(int i = 1; i<n-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]) peaks.pb(i);
    }
    peaks.pb(n);
    

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

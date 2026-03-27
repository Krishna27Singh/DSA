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
make array empty 


*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int cnt = 0;

    // maximum element index uptil index i, for each i from 0 to n-1
    vector<int> mx(n);
    mx[0] = 0;
    int maxIdx = 0;
    for(int i = 1; i<n; i++){
        if(a[i] > a[maxIdx]) maxIdx = i;
        else if(a[i] == a[maxIdx]) maxIdx = max(maxIdx, i);
        mx[i] = maxIdx;
    }

    // for(auto i: mx) cout<<i<<" ";
    // cout<<endl;

    while(true){

        int maxIdx = mx[n-1];
        n = maxIdx;
        cnt++;
        if(n <= 0) break;
    }

    cout<<cnt<<endl;

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

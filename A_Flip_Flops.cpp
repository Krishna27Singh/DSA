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
5 18 30
n c k
1 2 93 84 2

36 
k = 13
51
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll n, c, k; cin>>n>>c>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    sort(all(a));

    if(a[0] > c){
        cout<<c<<endl;
        return;
    }

    for(int i = 0; i<n; i++){
        if(a[i] > c){
            cout<<c<<endl;
            return;
        }
        if(k >= c - a[i]){
            // cout<<"exe"<<endl;
            k -= (c-a[i]);
            a[i] = c;
            // cout<<k<<endl;
            // cout<<c<<endl;
        }
        else{
            a[i] += k;
            k = 0;
        }
        c += a[i];
        // cout<<"c: "<<c<<"ai: "<<a[i]<<"k: "<<k<<endl;
    }

    cout<<c<<endl;
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

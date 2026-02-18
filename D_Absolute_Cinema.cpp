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
f(0) = a1 + 2a2 +... + (n-1)a(n-1) 
sum1 = a1 + 2a2 +... + (n-2)a(n-2)
a(n-1) = f(0)-sum1/n-1

f(n-1) = (n-1)a0 + (n-2)a1 +... + a(n-2)
sum2 = (n-2)a1 + (n-3)a2 +... a(n-2)
a0 = f(n-1)-sum2/n-1
*/

void solve(){
    int n; cin>>n;
    vector<ll> f(n);
    for(int i = 0; i<n; i++) cin>>f[i];

    vector<ll> a(n);
    for(int x = 1; x<n-1; x++){
        a[x] = (f[x-1] + f[x+1] - 2*f[x])/2;
    }

    ll sum1 = 0;
    for(int i = 1; i<n-1; i++) sum1 += i*a[i];
    a[n-1] = (f[0]-sum1)/(n-1);
    ll sum2 = 0;
    for(int i = 1; i<n-1; i++) sum2 += (n-1-i)*a[i];
    a[0] = (f[n-1]-sum2)/(n-1);

    for(auto i: a) cout<<i<<" ";
    cout<<endl;
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

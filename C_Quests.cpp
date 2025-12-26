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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    ll ans = 0;
    ll len = min(n,k);
    ll maxiBi = 0;
    ll sum = 0;
    for(int i = 0; i<len; i++){
        sum += a[i];
        maxiBi = max(maxiBi, b[i]);
        ans = max(ans, sum + maxiBi*(k-i-1));
    }

    // Output
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

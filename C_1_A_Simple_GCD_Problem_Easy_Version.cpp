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

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i]; 

    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        if (i == 0) {
            if (a[0] > gcd(a[0], a[1])) {
                cnt++;
            }
        } 
        else if (i == n - 1) {
            if (a[n-1] > gcd(a[n-2], a[n-1])) {
                cnt++;
            }
        } 
        else {
            ll l = gcd(a[i-1], a[i]);
            ll r = gcd(a[i], a[i+1]);
            ll m = lcm(l, r);
            
            if (a[i] > m) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
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

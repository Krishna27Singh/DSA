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
operations allowed

1) end the game
2) swap ai and aj. cost = j - i
ai and aj can be same also -> cost = 0;
do nothing with array and cost

alice -> maximize fa
bob -> minimize fa

final value of fa?


*/

void solve(){
    int n;
        cin >> n;
 
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(i % 2) ans -= a[i];
            else ans += a[i];
        }
 
        ll init = ans;
 
        for(int i = 0; i < n; i++) ans = max(ans, init + i - (i % 2));
 
        ll min_even = LLONG_MAX / 2, min_odd = LLONG_MAX / 2;
        for(int i = 0; i < n; i++){
            if(i % 2){
                ans = max(init + i + a[i] + a[i] - min_even, ans);
                min_odd = min(min_odd, i - a[i] - a[i]);
            }
            else{
                ans = max(init + i - a[i] - a[i] - min_odd, ans);
                min_even = min(min_even, i + a[i] + a[i]);
            }
        }
 
        cout << ans << '\n';

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

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

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 
    
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1);
        res /= i;
    }
    return res;
}

void solve(){
    ll n, maxMoves; cin>>n>>maxMoves;

    int d = 0;
    ll temp = n;
    while(temp>1){
        temp = temp>>1;
        d++;
    }

    ll ans = 0;
    if(d+1>maxMoves) ans++;

    for(int msb = 1; msb<=d; msb++){
        int rem = msb-1;
        int mini = maxMoves-msb+1;
        if(mini<0) mini = 0;
        for(int i = mini; i<=rem; i++){
            ans += nCr(rem, i);
        }
    }

    cout<<ans<<endl;
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

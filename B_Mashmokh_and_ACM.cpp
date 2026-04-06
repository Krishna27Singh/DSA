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
bi % bi+1 == 0 for each number 0 -> i-1

b1, b2, b3, ... bk 
number of sequence such that b1 % b2 == 0, b2 % b3 == 0, ... bk-1 % bk == 0
and 1 <= b1 <= b2 <= b3 <= ... <= bk <= n

k = 5, n = 7
one of possible sequence is 

dp[i][j] = number of sequences of length i ending with j
dp[i][j] = sum of dp[i-1][k] for all k such that k % j == 0
*/

/*
****************************************** Testing ****************************************************
n = 6, k = 4
b1, b2, b3, b4

b4 = 6 -> b3 can be 1, 2, 3, 6 -> 


*/

void solve(){
    int n, k; cin>>n>>k;
    ll ans = 0;

    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i<=n; i++) dp[1][i] = 1;
    for(int i = 2; i<=k; i++){
        for(int j = 1; j<=n; j++){
            for(int x = j; x<=n; x+=j){
                dp[i][j] = (dp[i][j] + dp[i-1][x]) % MOD;
            }
        }
    }

    cout<<accumulate(all(dp[k]), 0LL) % MOD<<endl;



    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

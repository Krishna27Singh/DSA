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
width -> 2
height -> n
min width and height of brick -> 1
(0, 0) -> (2, n)

2 cases
1) extend the block
2) start a new block

cases in extending the block
 |
 |
 |
 |

 |
 |
 |
 -
 |

 |
 |
 -
 |
 -
 |

 |

for tower of width 1, we have 2 cases

- extend the height 
- start a new block

dry run for n = 4;

rec(0, n) -> rec(1, n) -> rec(2, n) -> rec(3, n) -> rec(4, 4)
                                                  <-  


f(n, 2) -> the number of distinct towers that can be formed for a tower of height n and with 2

at any point i can either increase the height of the tower 
or
split the current brick of width
*/

// int rec(int i, int state, int n, vector<vector<int>> &dp){
//     if(i == n) return 1;
//     if(i == 0){
//         return dp[i][state] = ((rec(i+1, 0, n, dp))%MOD + (rec(i+1, 1, n, dp))%MOD)%MOD;
//     }
//     if(dp[i][state] != -1) return (dp[i][state])%MOD;

//     int case1 = 0; int case2 = 0;
//     if(state == 0) case1 = ((2*(rec(i+1, 0, n, dp))%MOD)%MOD + (rec(i+1, 1, n, dp))%MOD)%MOD;
//     else case2 = ((4*(rec(i+1, 1, n, dp))%MOD)%MOD + (rec(i+1, 0, n, dp))%MOD)%MOD;

//     return dp[i][state] = (case1 + case2)%MOD;
// }

vector<vector<int>> dp(1e6+1, vector<int>(2, 0));

void solve(){
    int n; cin>>n;

    dp[n][0] = 1;
    dp[n][1] = 1;
    for(int i = n-1; i>=0; i--){
        dp[i][0] = (2LL*dp[i+1][0] + dp[i+1][1])%MOD;
        dp[i][1] = (4LL*dp[i+1][1] + dp[i+1][0])%MOD;
    }

    cout<<(dp[1][0] + dp[1][1])%MOD<<endl;

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

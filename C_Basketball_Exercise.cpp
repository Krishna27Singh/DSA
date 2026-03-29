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
h[0][i] -> level 1
h[1][i] -> level 2

neet to choose players (any number) such that 

# no consecutive 2 players are chosen of the same level
# the sum of the heights of the chosen players is maximum
# the index of each chosen player is less than the index of the next chosen player

f(i, j) -> the maximum sum of heights if we choose player i from level j
j -> from which level did we choose the previous player ?
i -> the index of the current player we are choosing
j = 0 -> we chose the previous player from level 1
j = 1 -> we chose the previous player from level 2
j = 2 -> we didn't choose any previous player

if(j != 2){
    f(i, j) = max(f(i-1), 1-j) + h[j][i], f(i-1, 2))
}
else{
    f(i, j) = max(f(i-1, 0) + h[0][i], f(i-1, 1) + h[1][i], f(i-1, 2))
}



*/

/*
****************************************** Testing ****************************************************

*/

ll dp[100005][3];

void solve(){
    int n; cin>>n;
    vector<vector<int>> h(2, vector<int>(n));
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++) cin>>h[i][j];
    }

    dp[0][0] = h[0][0];
    dp[0][1] = h[1][0];
    dp[0][2] = 0;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<3; j++){
            if(j != 2) dp[i][j] = max(dp[i-1][1-j], dp[i-1][2]) + h[j][i];
            else dp[i][j] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }
    }

    ll ans = 0;
    for(int j = 0; j<3; j++) ans = max(ans, dp[n-1][j]);

    cout<<ans<<endl;
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

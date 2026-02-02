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

int rec(int idx, int len, vector<int> &a, vector<vector<int>> &dp){
    if(idx == a.size()){
        if(len == 0) return 0;
        return INF;
    } 
    if(dp[idx][len] != -1) return dp[idx][len];

    //not take this element
    int notTake = 1 + rec(idx+1, len, a, dp);

    //take this element
    int take = 0;
    if(len == 0){
        take = rec(idx+1, a[idx], a, dp);
    }
    else{
        take = rec(idx+1, len-1, a, dp);
    }
    return dp[idx][len] = min(take, notTake);
}

void solve(){
        const int N = 200000 + 5;
        int n, a[N], dp[N], buc[N];
        cin >> n;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) buc[i] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = min(dp[i - 1] + 1, buc[a[i]]);
            buc[a[i]] = min(buc[a[i]], dp[i - 1]);
        }
        cout << n - dp[n] << '\n';

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

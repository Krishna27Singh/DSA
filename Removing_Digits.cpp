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

int rec(int n, vector<int> &dp){
    if(n/10 == 0) return 1;
    if(dp[n] != -1) return dp[n];

    int num = n;
    int ans = INF;
    while(num){
        int digit = num%10;
        num /= 10;
        if(digit == 0) continue;
        ans = min(ans, 1 + rec(n-digit, dp));
    }
    return dp[n] = ans;
}

void solve(){
    int n; cin>>n;
    vector<int> dp(n+1, 0);

    // cout<<rec(n, dp)<<endl;

    for(int i = 0; i<10; i++) dp[i] = 1;
    for(int num = 10; num<=n; num++){
        int temp = num;
        int ans = INF;
        while(temp){
            int digit = temp%10;
            temp /= 10;
            if(digit == 0) continue;
            ans = min(ans, 1 + dp[num-digit]);
        }
        dp[num] = ans;
    }

    cout<<dp[n]<<endl;

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

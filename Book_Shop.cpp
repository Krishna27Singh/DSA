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
const int NEGINF = -1e8;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

int rec(int i, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
    if(i == price.size()) return 0;
    if(dp[i][x] != -1) return dp[i][x];

    //don't take this
    int notTake = 0 + rec(i+1, x, price, pages, dp);
    //take this
    int take = 0;
    if(x>=price[i]) take = pages[i] + rec(i+1, x - price[i], price, pages, dp);
    return dp[i][x] = max(take, notTake);
}

void solve(){
    int n, x; cin>>n>>x;
    vector<int> price(n);
    for(int i = 0; i<n; i++) cin>>price[i];
    vector<int> pages(n);
    for(int i = 0; i<n; i++) cin>>pages[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // cout<<rec(0, x, price, pages, dp)<<endl;

    for(int i = n-1; i>=0; i--){
        for(int w = 0; w<=x; w++){
            //don't take this
            int notTake = 0 + dp[i+1][w];
            //take this
            int take = 0;
            if(w>=price[i]) take = pages[i] + dp[i+1][w - price[i]];
            dp[i][w] = max(take, notTake);
        }
    }

    cout<<dp[0][x]<<endl;

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

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

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(s1[i] == s2[j]) return 0 + f(i-1, j-1, s1, s2, dp);
    if(dp[i][j] != -1) return dp[i][j];

    int insert = 1 + f(i, j-1, s1, s2, dp);
    int dlt = 1 + f(i-1, j, s1, s2, dp);
    int replace = 1 + f(i-1, j-1, s1, s2, dp);

    return dp[i][j] = min(insert, min(dlt, replace));
}

void solve(){
    string s1; cin>>s1;
    string s2; cin>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout<<f(n-1, m-1, s1, s2, dp)<<endl;


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

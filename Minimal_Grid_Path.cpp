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
initially s = "";
move from (0, 0) -> (n-1, n-1);

*/

string f(int row, int col, vector<vector<char>> &grid, int n, vector<vector<string>> &dp){
    if(row == n-1 && col == n-1) return dp[row][col] = string(1, grid[row][col]);
    if(row >= n || col>=n) return string(2*n, 'Z');
    if(dp[row][col] != string(2*n, 'Z')) return dp[row][col];

    string down = string(1, grid[row][col]) + f(row+1, col, grid, n, dp);
    string right = string(1, grid[row][col]) + f(row, col+1, grid, n, dp);

    // s = s + min(down, right);
    return dp[row][col] = min(down, right);
}

void solve(){
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin>>grid[i][j];
    }
    vector<vector<string>> dp(n+1, vector<string>(n+1, string(2*n, 'Z'))); 

    // string s = "";
    // cout<<f(0, 0, grid, n, dp)<<endl;

    dp[n-1][n-1] = string(1, grid[n-1][n-1]);
    for(int row = n-1; row>=0; row--){
        for(int col = n-1; col>=0; col--){
            if (row == n-1 && col == n-1) continue;
            string down = string(1, grid[row][col]) + dp[row+1][col];
            string right = string(1, grid[row][col]) + dp[row][col+1];

            // s = s + min(down, right);
            dp[row][col] = min(down, right);
        }
    }

    cout<<dp[0][0]<<endl;

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

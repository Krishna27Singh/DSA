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

// int f(int row, int col, vector<vector<int>> &dp){
//     if(row == col) return 0;
//     if(dp[row][col] != -1) return dp[row][col];

//     if(col > row){
//         return dp[row][col] = 1 + f(row, col - row, dp);
//     }
//     return dp[row][col] = 1 + f(row - col, col, dp);
// }

int f(int row, int col, vector<vector<int>> &dp){
    if(row == col) return 0;
    if(dp[row][col] != -1) return dp[row][col];

    // cut by rows
    int rowMin = INF;
    for(int newRow = 1; newRow<row; newRow++){
        rowMin = min(rowMin, 1 + f(newRow, col, dp) + f(row-newRow, col, dp));
    }
    //cut by columns
    int colMin = INF;
    for(int newCol = 1; newCol<col; newCol++){
        colMin = min(colMin, 1 + f(row, newCol, dp) + f(row, col-newCol, dp));
    }

    // cout<<"rowMin: "<<rowMin<<" colMin: "<<colMin<<endl;

    return dp[row][col] = min(rowMin, colMin);
}

void solve(){
    int r, c; cin>>r>>c;
    vector<vector<int>> dp(r+1, vector<int>(c+1, INF));

    for(int row = 1; row<=r; row++){
        for(int col = 1; col<=c; col++){
            if(row == col){
                dp[row][col] = 0;
                continue;
            }
            int rowMin = INF;
            for(int newRow = 1; newRow<row; newRow++){
                rowMin = min(rowMin, 1 + dp[newRow][col] + dp[row-newRow][col]);
            }
            int colMin = INF;
            for(int newCol = 1; newCol<col; newCol++){
                colMin = min(colMin, 1 + dp[row][newCol] + dp[row][col-newCol]);
            }

            dp[row][col] = min(rowMin, colMin);
        }
    }

    cout<<dp[r][c]<<endl;

    // cout<<f(row, col, dp)<<endl;
    // cout<<f(row, col, dp)<<endl;
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

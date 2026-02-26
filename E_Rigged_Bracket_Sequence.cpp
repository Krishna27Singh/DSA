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

int rec(int i, int j, vector<vector<char>> &grid){
    if(i == grid[0].size()-1 && j == grid[0].size()-1) return 1;
    if(i>=grid[0].size() || j>=grid[0].size()) return 0;

    int ans = 0;
    //move down
    ans = (ans + (rec(i+1, j, grid))%MOD)%MOD;
    //move right
    ans = (ans + (rec(i, j+1, grid))%MOD)%MOD;

    return ans;
}

void solve(){
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin>>grid[i][j];
    }

    cout<<rec(0, 0, grid)<<endl;

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

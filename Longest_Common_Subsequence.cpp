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

int f(int idx1, int idx2, vector<int> &a, vector<int> &b, vector<vector<int>> &dp){
    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(a[idx1] == b[idx2]) return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, a, b, dp);
    
    return dp[idx1][idx2] = max(f(idx1, idx2-1, a, b, dp), f(idx1-1, idx2, a, b, dp));
}

void solve(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(m);
    for(int i = 0; i<m; i++) cin>>b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    int LCSLen = f(n-1, m-1, a, b, dp);

    cout<<LCSLen<<endl;

    vector<int> lcs;
    int i = n-1;
    int j = m-1;
    while(i>=0 && j>=0){
        // cout<<"debug"<<endl;
        if(a[i] == b[j]){
            lcs.push_back(a[i]);
            i--;
            j--;
        }
        else if(i>0 && dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(all(lcs));
    for(auto i: lcs) cout<<i<<" ";
    cout<<endl;
    // cout<<lcs.size()<<endl;

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

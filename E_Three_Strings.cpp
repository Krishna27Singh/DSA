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
string c if formed
-> either string a or string b is chosen
-> 0th character is removed and appended to the end of string c
-> process ends until on of the string ran out
-> remaining character of the string is appended to the end of string c

at each step either choose a[0] or b[0]


*/

int f(int i, int j, string &a, string &b, string &c, vector<vector<int>> &dp) {
    int pos = i + j;
    if (pos == (int)c.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INF;

    if (i < (int)a.size()) {
        int cost = (a[i] != c[pos]);
        ans = min(ans, cost + f(i + 1, j, a, b, c, dp));
    }

    if (j < (int)b.size()) {
        int cost = (b[j] != c[pos]);
        ans = min(ans, cost + f(i, j + 1, a, b, c, dp));
    }

    return dp[i][j] = ans;
}


void solve(){
    string a, b, c; cin>>a>>b>>c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    // int n1 = a.size();
    // int n2 = b.size();
    // int n3 = n1 + n2;
    int na = a.size();
    int nb = b.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, -1));

    cout<<f(0, 0, a, b, c, dp)<<endl;


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

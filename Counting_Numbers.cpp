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
Your task is to count the number of integers between a and b where no two adjacent digits are the same.

*/

long long dp[20][11][2][2];

ll rec(int index, int lastDigit, bool leadingZeros, bool tight, string s){
    if(index == s.size()) return 1;
    if(dp[index][lastDigit][leadingZeros][tight] != -1) return dp[index][lastDigit][leadingZeros][tight];

    ll ans = 0;
    int limit;
    if(tight) limit = s[index] - '0';
    else limit = 9;

    for(int digit = 0; digit <= limit; digit++){
        if(leadingZeros == false && digit == lastDigit) continue;

        bool nextLeadingZeros = (leadingZeros && digit == 0);
        bool nextTight = (tight && digit == limit);
        int nextLastDigit;
        if(nextLeadingZeros) nextLastDigit = 10;
        else nextLastDigit = digit;

        ans += rec(index + 1, nextLastDigit, nextLeadingZeros, nextTight, s);
    }
    
    return dp[index][lastDigit][leadingZeros][tight] = ans;
}

ll solve2(ll n){
    if(n<0) return 0;
    if(n==0) return 1;

    string s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return rec(0, 10, true, true, s);
}

void solve1(){
    ll a, b; cin>>a>>b;
    ll ans = solve2(b) - solve2(a-1);
    
    cout<<ans<<endl;
}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve1();
    return 0;
}

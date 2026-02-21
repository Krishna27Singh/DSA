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

// const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************
remove at position y, 2y, 3y, 4y
repeat this operation x times
initial n = 1e12
if k>n return -1
else return integer at kth position in the modified sequence


*/

const long long INF = 1000000000000LL + 1;

void solve(){
    int x;
    long long y, k;
 
    cin >> x >> y >> k;
 
    long long l = 1, r = INF;
    long long m;
 
    while(l <= r){
        m = l + (r - l) / 2;
        long long ost = (m - 1);
        for (int i = 0; i < x; i++){
            ost -= ost / y;
        }
        if (ost + 1 > k){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
 
    if (r == INF){
        cout << -1 << '\n';
    }
    else{
        cout << r << '\n';
    }
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

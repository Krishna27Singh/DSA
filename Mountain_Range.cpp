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
h1 h2 h3 ... hn
a -> b
if h(a) > h(b) && h(a) > any mountain in between a and b

maximum visit of mountains?
start an any mountain

two cases
one from start to end
ont form end to start

landing at a mountain or not that is my choice and it will eventually decide the answer actually

I can use the dp states [idx][current total mountains] but this is square complexity

*/

int f(int idx, vector<int> &h){

    // land on this mountain
    int land = 1 + f(idx + 1, h);
    //not land on this mountian
    int notLand = 
}



void solve(){
    int n; cin>>n;
    vector<int> h(n);
    for(int i = 0; i<n; i++) cin>>h[i];



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

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
(a|b) - (a&c) = d
find such a, if exist
if a bit is turned on in d then it must be turned on in (a|b) and turned off in (a&c)
if a bit is turned of in d then it can be turned on or off in (a|b) and (a&c)

iterate bits in d
for(bit in d){
    // lets find out the current bit in a
    if(bit is on){
        // check if bit is turned on or off in b
        if(bit is on in b){
            // bit in a can either be turned on or off 
            // now check if bit is turned on or off in c
            if(bit is on in c){
                //bit in a has to be turned off 
        }
    }
    else{
        
    }
}
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll b, c, d; cin>>b>>c>>d;



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

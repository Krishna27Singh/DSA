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

/*
****************************************** Testing ****************************************************
n * k ( 1 <= k <= m)

roundest possible n
if two more more possibilities then max n 
can't rount it more ? cout<<n*m;

2 5 -> 10
5 2 -> 10 
max zeros in m
*/

void solve(){
    ll n,m; cin>>n>>m;
    ll orgn = n;
    ll orgm = m;

    int case3 = -1;
    int temp = m;
    while(temp){
        case3++;
        temp /= 10;
    }

    while(n%10 == 0){
        n /= 10;
    }

    int n2, n5, m2, m5;
    n2 = n5 = m2 = m5 = -1;

    temp = 1;
    while(temp <= n){
        temp *= 2;
        n2++;
    }
    temp = 1;
    while(temp <= n){
        temp *= 5;
        n5++;
    }
    temp = 1;
    while(temp <= m){
        temp *= 2;
        m2++;
    }
    temp = 1;
    while(temp <= m){
        temp *= 5;
        m5++;
    }

    int case1 = min(n2, m5);
    int case2 = min(n5, m2);

    int ans = max(case1, max(case2, case3));

    if(ans == 0){
        cout<<orgn*orgm;
        return;
    }

    if(case3 > case1 && case3 > case2){
        cout<<orgn*pow(10, case3);
        return;
    }

    if(case1 > case2){
        
    }
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

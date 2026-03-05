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
const ll MOD = 998244353;

/*
****************************************** APPROACH **************************************************
1111...
suppose the length of this is l
then to choose 1 index to not delete will be lC1
and deleting all the other indices in all the possible order of arrangements will be -> (l-1)! 
so we just need to calculate l 

and we need to multiply all these possible comibinations

minimum numbers to delete = summations(l-1) | l >= 2
*/

/*
****************************************** Testing ****************************************************

*/
const ll MAXN = 1e6 + 5;
ll fact[MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i)%MOD;
    }
}

void solve(){
    string s; cin>>s;
    ll n = s.size();

    vector<ll> segs;
    for(int i = 0; i<n; i++){
        ll l = 0;
        char ch = s[i];
        while(i<n && s[i] == ch){
            l++; i++;
        }
        i--;
        if(l < 2) continue;
        segs.pb(l);
    }

    ll ans = 1;
    ll mini = 0;
    for(auto l : segs){
        mini += l-1;
        ans = (ans * l)%MOD;
    }
    ans = (ans * fact[mini])%MOD;
    if(ans == 0) ans = 1;

    cout<<mini<<" "<<ans<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    precompute();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

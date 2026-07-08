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

*/

void solve(){
    ll n; cin>>n;
    string s; cin>>s;

    ll ans = n*(n+1)/2;
    vector<ll> p(3, 0);
    ll curr = 0;
    p[0] = 1;
    for(int i = 0; i<n; i++){
        curr = (curr + (s[i]-'0'+1))%3;
        p[curr]++;
    }

    ll l = 1;
    for(int i = 1; i<n; i++){
        if(s[i] != s[i-1]) l++;
        else{
            if(l>=3){
                ans -= (l-1)/2 * (l - (l-1)/2 - 1);
                l = 1;
            } else l = 1;
        }
    }
    if(l >= 3){
        ans -= (l-1)/2 * (l - (l-1)/2 - 1);
    }
    for(int i = 0; i<3; i++){
        ans -= p[i]*(p[i]-1)/2;
    }

    cout<<ans<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1; cin >> tc;
    while (tc--) solve();
    return 0;
}

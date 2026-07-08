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
    vector<ll> c(n);
    for(int i = 0; i<n; i++) cin>>c[i];
    ll si = 0;
    for(auto i : c) si += i;
    if(si < 3){
        cout<<0<<endl;
        return;
    }

    ll cnt1 = 0;
    for(auto i : c) if(i == 1) cnt1++;
    if(cnt1 == 0){
        cout<<si<<endl;
        return;
    }
    if(cnt1 == n-1) cnt1--;

    
    for(int i = 0; i<n; i++){
        if(c[i] != 1){
            if(c[i]/2 - 1 > 0){
                int del = min(cnt1, c[i]/2 - 1);
                cnt1 -= del;
            }
        }
    }
    

    cout<<si - cnt1<<endl;

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

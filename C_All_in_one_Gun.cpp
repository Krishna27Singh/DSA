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
damage -> ai
initial health -> h
fires 1 bullet in 1 second
reload time -> k second
reloding makes the sequence same again

can make a single swap before starting to kill

minimum seconds to kill ?

bullet fires from indice 0



*/

void solve(){
    int n, h, k; cin>>n>>h>>k;
    vector<int> a(n);
    ll totalDamage = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        totalDamage += a[i];
    }

    ll ans = 0;
    ans += (h/totalDamage)*n + (h/totalDamage)*k;
    h = h % totalDamage;
    if(h == 0){
        cout<<ans-k<<endl;
        return;
    }

    // int ending = 0;
    // int temp = h;
    // while(temp > 0){
    //     temp -= a[ending];
    //     ending++;
    // }
    // ending--;
    // if(ending == 0){
    //     ans++;
    //     cout<<ans<<endl;
    //     return;
    // }

    // int remMaxIdx;
    // int maxi = a[ending];
    // remMaxIdx = ending;
    // for(int i = ending+1; i<n; i++){
    //     if(a[i] > maxi){
    //         maxi = a[i];
    //         remMaxIdx = i;
    //     }
    // }

    vector<int> suf(n, 0);
    suf[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        suf[i] = max(suf[i+1], a[i]);
    }

    ll cs = 0;
    int cm = INT_MAX;
    
    for(int i = 0; i<n; i++){
        cs += a[i];
        cm = min(cm, a[i]);
        ll maxi = cs;
        if(i+1 < n && suf[i+1] > cm){
            maxi += (suf[i+1] - cm);
        }
        if(maxi >= h){
            ans += i+1;
            break;
        }
    }

    cout<<ans<<endl;

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

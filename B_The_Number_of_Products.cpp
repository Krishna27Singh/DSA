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
    vector<ll> a(n);
    for(int i = 0; i<n; i++){
        ll x; cin>>x;
        if(x>0) a[i] = 1;
        else a[i] = -1;
    }

    ll tp = 0;
    ll tn = 0;
    ll pref = 1;
    ll pp = 1;
    ll pn = 0;

    for(int i = 0; i<n; i++){
        // r = i ! 
        pref *= a[i];
        if(pref > 0){
            tp += pp;
            tn += pn;
            pp++;
        }
        else{
            tp += pn;
            tn += pp;
            pn++;
        }
    }

    cout<<tn<<" "<<tp<<endl;



    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

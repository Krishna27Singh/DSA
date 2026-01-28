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

void solve(){
    ll n, x; cin>>n>>x;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i<n; i++) cin>>a[i]>>b[i]>>c[i];

    ll temp = 0;
    for(int i = 0; i<n; i++){
        temp += (b[i]-1)*a[i];
    }

    if(temp >= x){
        cout<<0<<endl;
        return;
    }

    x -= temp;

    ll maxi = -1e9;
    for(int i = 0; i<n; i++){
        maxi = max(maxi, a[i]*b[i] - c[i]);
    }

    if(maxi<=0){
        cout<<-1<<endl;
        return;
    }

    cout<<x/maxi<<endl;

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

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
    ll n; cin>>n;
    vector<ll> b(2*n);
    for(int i = 0; i<2*n; i++){
        cin>>b[i];
    }

    vector<ll> a(2*n+1, 0);
    sort(b.begin(), b.end());
    
    a[0] = b[2*n-1];
    a[2*n] = b[0];
    ll left = 1;
    ll right = 2*n-2;
    ll idx = 1;
    ll a2n = a[0] + a[2*n];
    while(left < right){
        a[idx] = b[left];
        a[idx+1] = b[right];
        a2n += b[right]-b[left];
        idx += 2;
        left++;
        right--;
    }
    a[2*n-1] = a2n;
    for(auto i : a) cout<<i<<" ";
    cout<<endl;

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

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
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    if(b[n-1] > a[n-1]) a[n-1] = b[n-1];
    for(int i = n-2; i>=0; i--){
        if(max(b[i], a[i+1]) > a[i]){
            a[i] = max(b[i], a[i+1]);
        }
    }

    for(auto it: a){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 0; i<n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }

    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;

        cout<<prefix[r+1] - prefix[l]<<" ";

    }

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

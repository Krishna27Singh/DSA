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
    int n; cin>>n;
    vector<pair<int, bool>> a(n+1);
    for(int i = 1; i<=n; i++){
        int x; cin>>x;
        a[i] = mp(x, false);
    }

    for(int i = 1; i<=n/2; i++){
        if(a[i].second) continue;
        vector<int> indices;
        vector<int> values;
        for(int k = i; k<=n; k=k*2){
            indices.pb(k);
            values.pb(a[k].first);
            a[k].second = true;
        }
        sort(all(values));
        int len = indices.size();
        for(int k = 0; k<len; k++){
            a[indices[k]].first = values[k];
        }
    }

    if(is_sorted(a.begin(), a.end())) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    

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

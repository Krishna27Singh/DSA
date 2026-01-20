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
    int n, m, h; cin>>n>>m>>h;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(m);
    vector<int> c(m);
    for(int i = 0; i<m; i++){
        cin>>b[i];
        cin>>c[i];
    }

    vector<int> orga = a;
    vector<int> changed;

    for(int i = 0; i<m; i++){
        int idx = b[i]-1;
        int del = c[i];
        // cout<<"before "<<idx<<" "<<a[idx]<<endl;
        a[idx] += del;
        changed.push_back(idx);
        // cout<<"after "<<idx<<" "<<a[idx]<<endl;
        if(a[idx]>h){
            for(auto j: changed) a[j] = orga[j];
            changed.clear();
        }
    }

    for(auto i: a) cout<<i<<" ";
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

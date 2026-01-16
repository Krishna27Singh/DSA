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

*/

void solve(){
    int n; cin>>n;
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin>>p[i];
    vector<int> q(n);
    for(int i = 0; i<n; i++) cin>>q[i];

    vector<pair<int, int>> pIdx;
    for(int i = 0; i<n; i++) pIdx.push_back(make_pair(p[i], i));
    vector<pair<int, int>> qIdx;
    for(int i = 0; i<n; i++) qIdx.push_back(make_pair(q[i], i));
    sort(pIdx.begin(), pIdx.end());
    sort(qIdx.begin(), qIdx.end());

    // for(auto i: pIdx) cout<<i.first<<" "<<i.second<<endl;
    // cout<<endl;
    // for(auto i: qIdx) cout<<i.first<<" "<<i.second<<endl;
    // cout<<endl;

    vector<ll> r(n, 0);
    if(pIdx[n-1].second + qIdx[n-1].second < n)
        r[pIdx[n-1].second + qIdx[n-1].second] = pow(2, pIdx[n-1].first) + pow(2, pIdx[n-1].first);

    for(int i = n-2; i>=0; i--){
        if(qIdx[i].second + pIdx[n-1].second < n && r[qIdx[i].second + pIdx[n-1].second]==0)
            r[qIdx[i].second + pIdx[n-1].second] = pow(2, qIdx[i].first) + pow(2, pIdx[n-1].first);
        
        if(pIdx[i].second + qIdx[n-1].second < n && r[pIdx[i].second + qIdx[n-1].second]==0)
            r[pIdx[i].second + qIdx[n-1].second] = pow(2, pIdx[i].first) + pow(2, qIdx[n-1].first);

    }

    for(auto i: r) cout<<i<<" ";
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

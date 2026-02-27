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
    int n, x, y; cin>>n>>x>>y;
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin>>p[i];

    int mini = INT_MAX;
    int miniIdx = -1;
    for(int i = x; i<y; i++){
        if(p[i] < mini){
            mini = p[i];
            miniIdx = i;
        }
    }
    vector<int> v;
    for(int i = 0; i<x; i++) v.push_back(p[i]);
    for(int i = y; i<n; i++) v.push_back(p[i]);

    int len = v.size();
    int k = v.size();
    for(int i = 0; i<len; i++){
        if(v[i] > mini){
            k = i;
            break;
        }
    }

    for(int i = 0; i<k; i++) cout<<v[i]<<" ";
    for(int i = miniIdx; i<y; i++) cout<<p[i]<<" ";
    for(int i = x; i<miniIdx; i++) cout<<p[i]<<" ";
    for(int i = k; i<len; i++) cout<<v[i]<<" ";
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

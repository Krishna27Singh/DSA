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
standing at the index there are few cases
1) continue to extend the segment
2) end the segment here in that case we need to check if a[i] = segment len, start a new segment

2 cases in starting a new segment
1) take the value of a[i] as segment len and continue till segment len
2) take the value of segment len afterwards
*/

bool f(int idx, int len, vector<int> &b) {
    int n = b.size();
    
    if (idx == n) {
        return len == 0; 
    }
    
    bool possible = false;
    if (f(idx + 1, len + 1, b)) return true;

    if (len > 0 && b[idx] == len) {
        if (f(idx + 1, 0, b)) return true;
    }

    if (len == 0) {
        int jumpDist = b[idx] + 1;
        if (idx + jumpDist <= n) {
            if (f(idx + jumpDist, 0, b)) return true;
        }
    }

    return false;
}

void solve(){
    int n; cin>>n;
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    if(f(0, 0, b)) cout<<"YES"<<endl;
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

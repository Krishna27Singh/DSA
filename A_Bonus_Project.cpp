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
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    vector<long long> l(n);
    long long t = 0;
    
    for (int i = 0; i < n; ++i) {
        l[i] = a[i] / b[i];
        t += l[i];
    }

    vector<long long> c(n, 0);

    if (t >= k) {
        for (int i = n - 1; i >= 0; --i) {
            long long take = min((long long)k, l[i]);
            c[i] = take;
            k -= take; 
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << c[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

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

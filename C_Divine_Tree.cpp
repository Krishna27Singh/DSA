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
    d min -> n
    d max -> n(n+1)/2
*/

void solve(){
    int n, m; cin>>n>>m;
    ll maxSum = 1LL * n * (n + 1) / 2;
        if (m < n || m > maxSum) {
            cout << -1 <<endl;
            return;
        }

        vector<int> vals(n);
        for (int i = 0; i < n; i++) {
            vals[i] = i + 1;
        }

        ll rem = maxSum - m;

        for (int i = n - 1; i >= 0 && rem > 0; i--) {
            ll canReduce = vals[i] - 1;
            if (rem <= canReduce) {
                vals[i] -= rem;
                rem = 0;
            } else {
                rem -= canReduce;
                vals[i] = 1;
            }
        }
    
        int root = *max_element(vals.begin(), vals.end());
        cout << root << "\n";

        for (int i = 0; i < n; i++) {
            int node = i + 1;
            if (node == root) continue;

            if (vals[i] == node) {
                cout << node << " " << root << "\n";
            } else {
                cout << node << " " << vals[i] << "\n";
            }
        }

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

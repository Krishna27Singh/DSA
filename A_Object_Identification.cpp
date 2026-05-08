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
if recieves 0 then definitely directed graph

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n;
    cin >> n;
    vector<int> x(n + 1), isx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        isx[x[i]] = 1;
    }
    if (accumulate(isx.begin(), isx.end(), 0) == n) {
        int i1 = 0, in = 0;
        for (int i = 1; i <= n; i++) {
            if (x[i] == 1) {
                i1 = i;
            }
            if (x[i] == n) {
                in = i;
            }
        }
        cout << "? " << i1 << ' ' << in << endl;
        int ans;
        cin >> ans;
        if (ans < n - 1) {
            cout << "! A" << endl;
        } else if (ans > n - 1) {
            cout << "! B" << endl;
        } else {
            cout << "? " << in << ' ' << i1 << endl;
            cin >> ans;
            if (ans == n - 1) {
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!isx[i]) {
                cout << "? " << i << ' ' << 1 + (i == 1) << endl;
                int ans;
                cin >> ans;
                if (ans == 0) {
                    cout << "! A" << endl;
                } else {
                    cout << "! B" << endl;
                }
                return;
            }
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

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
    int n, x, s;
    cin >> n >> x >> s;

    string u;
    cin >> u;

    int cntA = 0;
    for(char c : u) {
        if(c == 'A') cntA++;
    }

    auto eval = [&](int m) {
        ll opened = 0;
        ll seated = 0;

        for(char c : u) {
            if(c == 'I') {
                if(opened < x) {
                    opened++;
                    seated++;
                }
            }
            else if(c == 'E') {
                if(seated < opened * 1LL * s) {
                    seated++;
                }
            }
            else {
                if(m > 0) {
                    m--;
                    if(opened < x) {
                        opened++;
                        seated++;
                    }
                }
                else {
                    if(seated < opened * 1LL * s) {
                        seated++;
                    }
                }
            }
        }

        return seated;
    };

    ll ans = 0;

    for(int m = 0; m <= cntA; m++) {
        ans = max(ans, eval(m));
    }

    cout << ans << '\n';
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

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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n;
    cin >> n;

    int N = 1 << n;
    vector<bool> used(N, false);
    vector<int> ans;

    int x = N - 1;
    while (true) {
        if (!used[x]) {
            used[x] = true;
            ans.push_back(x);
        }

        vector<int> extra;
        for (int y = 0; y < N; y++) {
            if (!used[y] && ( (y & x) == x )) {
                extra.push_back(y);
            }
        }

        sort(extra.begin(), extra.end());
        for (int y : extra) {
            used[y] = true;
            ans.push_back(y);
        }

        if (x == 0) break;

        int msb = 31 - __builtin_clz(x);
        x ^= (1 << msb);
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) ans.push_back(i);
    }

    // Output
    for (int v : ans) cout << v << " ";
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

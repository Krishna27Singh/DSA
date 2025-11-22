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

    vector<int> used(n + 1, 0);
    vector<vector<int>> groups;
    
    for (int o = 3; o <= n; o += 2) {
        vector<int> g;
        for (int x = o; x <= n; x += o) {
            g.push_back(x);
            used[x] = 1;
        }
        if (!g.empty()) groups.push_back(g);
    }

    vector<int> leftover;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) leftover.push_back(i);
    }

    vector<int> ans;

    int L = leftover.size();
    int li = 0;

    for (auto &g : groups) {

        for (int i = 0; i < (int)g.size(); i++) {
            ans.push_back(g[i]);
            if (i % 2 == 1 && li < L)
                ans.push_back(leftover[li++]);
        }
    }

    while (li < L)
        ans.push_back(leftover[li++]);

    for (int x : ans) cout << x << " ";
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

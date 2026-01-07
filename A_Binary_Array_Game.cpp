
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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve() {
    int n, k; cin>>n>>k;
    
    vector<bool> present(n + 2, false);
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < n + 2) {
            present[x] = true;
        }
    }
    
    int global_mex = 0;
    while (present[global_mex]) {
        global_mex++;
    }
    
    cout << min(global_mex, k - 1) << "\n";

    // Output
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

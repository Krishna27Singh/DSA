#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include<unordered_map>
#include <stack>
#include <string>
using namespace std;

void solve() {
    int n; 
    if (!(cin >> n)) return;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<int> p(n, -1);
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) ++j;
        int len = j - i;
        if (len == 1) {
            cout << -1 << '\n';
            return; 
        }
        for (int k = i; k < j - 1; ++k) p[k] = k + 2; 
        p[j - 1] = i + 1; 
        i = j;
    }

    for (int idx = 0; idx < n; ++idx) {
        if (idx) cout << ' ';
        cout << p[idx];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

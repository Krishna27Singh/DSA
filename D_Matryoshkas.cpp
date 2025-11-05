#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
#include<unordered_map>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<pair<long long,int>> v;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) ++j;
        v.emplace_back(a[i], j - i);
        i = j;
    }

    long long ans = 0;
    int m = (int)v.size();
    long long carry = v[0].second;

    for (int i = 0; i + 1 < m; ++i) {
        if (v[i+1].first != v[i].first + 1) {
            ans += carry;
            carry = v[i+1].second;
        } else {
            if (v[i+1].second > v[i].second) {
                carry += (v[i+1].second - v[i].second);
            } else {
                ans += (v[i].second - v[i+1].second);
                carry = v[i+1].second;
            }
        }
    }
    ans += carry;
    cout << ans <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

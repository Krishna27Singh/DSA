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
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) cin >> c[i];

    sort(a.begin(), a.end());

    vector<pair<int, int>> rewardMonsters, zeroMonsters;
    for (int i = 0; i < m; ++i) {
        if (c[i] != 0) rewardMonsters.push_back({b[i], c[i]});
        else zeroMonsters.push_back({b[i], c[i]});
    }

    sort(rewardMonsters.begin(), rewardMonsters.end()); 
    sort(zeroMonsters.begin(), zeroMonsters.end());     

    multiset<int> swords(a.begin(), a.end());
    int kills = 0;

    for (auto [life, reward] : rewardMonsters) {
        auto it = swords.lower_bound(life);
        if (it == swords.end()) continue;
        int used = *it;
        swords.erase(it);
        kills++;
        swords.insert(max(used, reward));
    }

    for (auto [life, reward] : zeroMonsters) {
        auto it = swords.lower_bound(life);
        if (it == swords.end()) continue;
        swords.erase(it);
        kills++;
    }

    cout << kills <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}

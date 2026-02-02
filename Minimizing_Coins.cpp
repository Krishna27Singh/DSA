#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int rec(int target, vector<int> &coins, vector<int> &dp) {
    if (target == 0) return 0;
    if (target < 0) return INF;

    if (dp[target] != -1) return dp[target];

    int ans = INF;
    for (int c : coins) {
        if (target >= c) {
            ans = min(ans, 1 + rec(target - c, coins, dp));
        }
    }
    return dp[target] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> dp(x + 1, -1);

    int res = rec(x, coins, dp);
    cout << (res >= INF ? -1 : res) << '\n';

    return 0;
}

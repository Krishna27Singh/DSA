#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        // dp[i][a_prev][b_prev]
        // where a_prev and b_prev are 0 or 1, representing source of prev value
        vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(2, vector<long long>(2, 0)));

        // Initialization at index 0
        dp[0][0][0] = 1; // take a[0] from a, b[0] from b (no swap)
        dp[0][1][1] = 1; // take a[0] from b, b[0] from a (swap)

        for (int i = 1; i < n; ++i) {
            for (int pa = 0; pa <= 1; ++pa) {
                for (int pb = 0; pb <= 1; ++pb) {
                    int prevA = (pa == 0 ? a[i-1] : b[i-1]);
                    int prevB = (pb == 0 ? b[i-1] : a[i-1]);
                    long long ways = dp[i-1][pa][pb];
                    if (ways == 0) continue;

                    // Option 1: no swap at i
                    if (a[i] >= prevA && b[i] >= prevB)
                        dp[i][0][0] = (dp[i][0][0] + ways) % MOD;

                    // Option 2: swap at i
                    if (b[i] >= prevA && a[i] >= prevB)
                        dp[i][1][1] = (dp[i][1][1] + ways) % MOD;
                }
            }
        }

        // Final answer is sum of all valid ways at index n-1
        long long result = 0;
        for (int pa = 0; pa <= 1; ++pa)
            for (int pb = 0; pb <= 1; ++pb)
                result = (result + dp[n-1][pa][pb]) % MOD;

        cout << result << '\n';
    }

    return 0;
}

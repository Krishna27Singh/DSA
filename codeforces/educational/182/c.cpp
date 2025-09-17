// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 998244353;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<int> a(n), b(n);
//         for (int &x : a) cin >> x;
//         for (int &x : b) cin >> x;

//         vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(2, vector<long long>(2, 0)));

//         dp[0][0][0] = 1; 
//         dp[0][1][1] = 1; 

//         for (int i = 1; i < n; ++i) {
//             for (int pa = 0; pa <= 1; ++pa) {
//                 for (int pb = 0; pb <= 1; ++pb) {
//                     int prevA = (pa == 0 ? a[i-1] : b[i-1]);
//                     int prevB = (pb == 0 ? b[i-1] : a[i-1]);
//                     long long ways = dp[i-1][pa][pb];
//                     if (ways == 0) continue;

//                     if (a[i] >= prevA && b[i] >= prevB)
//                         dp[i][0][0] = (dp[i][0][0] + ways) % MOD;

//                     if (b[i] >= prevA && a[i] >= prevB)
//                         dp[i][1][1] = (dp[i][1][1] + ways) % MOD;
//                 }
//             }
//         }

//         long long result = 0;
//         for (int pa = 0; pa <= 1; ++pa)
//             for (int pb = 0; pb <= 1; ++pb)
//                 result = (result + dp[n-1][pa][pb]) % MOD;

//         cout << result <<endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 998244353;

// int solve(int idx, vector<int> &a, vector<int> &b){

// }

// int main() {
//     int tc;
//     cin >> tc;

//     while (tc--) {
//         int n;
//         cin >> n;

//         vector<int> a(n), b(n);
//         for(int i = 0; i<n; i++) cin>>a[i];
//         for(int i = 0; i<n; i++) cin>>b[i];

//         int ans = 0;

//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 998244353;

int n;
vector<int> a, b;
int dp[1001][2][2]; 

int solve(int i, int pa, int pb) {
    if (i == n) return 1;

    if (dp[i][pa][pb] != -1) return dp[i][pa][pb];

    int prevA = (pa == 0 ? a[i - 1] : b[i - 1]);
    int prevB = (pb == 0 ? b[i - 1] : a[i - 1]);

    long long ways = 0;

    if (a[i] >= prevA && b[i] >= prevB)
        ways = (ways + solve(i + 1, 0, 0)) % MOD;

    if (b[i] >= prevA && a[i] >= prevB)
        ways = (ways + solve(i + 1, 1, 1)) % MOD;

    return dp[i][pa][pb] = ways;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        memset(dp, -1, sizeof(dp));  

        long long result = 0;

        if (n == 1) {
            result = 2; 
        } else {
            if (a[1] >= a[0] && b[1] >= b[0])
                result = (result + solve(2, 0, 0)) % MOD;

            if (b[1] >= a[0] && a[1] >= b[0])
                result = (result + solve(2, 1, 1)) % MOD;
        }

        cout << result << '\n';
    }

    return 0;
}

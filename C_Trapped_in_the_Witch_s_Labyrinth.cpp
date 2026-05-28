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
// mark ? where there is definitely a loop as 'T'

// iterate (skip ?) and mark vis = 1 for every node having loop 

// now iterate again and if any (U, D, L, R) of ? is marked as vis = 1 then mark that as 'T', otherwise mark as 'D' (end) 

// final iteration to calculate the answer
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<bool>> escapes(n, vector<bool>(m, false));
    vector<vector<int>> bad_dirs(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '?') {
                if (i == 0) bad_dirs[i][j]++;
                if (i == n - 1) bad_dirs[i][j]++;
                if (j == 0) bad_dirs[i][j]++;
                if (j == m - 1) bad_dirs[i][j]++;
                
                if (bad_dirs[i][j] == 4) {
                    escapes[i][j] = true;
                    q.push({i, j});
                }
            } else {
                bool out = false;
                if (grid[i][j] == 'U' && i == 0) out = true;
                if (grid[i][j] == 'D' && i == n - 1) out = true;
                if (grid[i][j] == 'L' && j == 0) out = true;
                if (grid[i][j] == 'R' && j == m - 1) out = true;
                
                if (out) {
                    escapes[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r + 1 < n && !escapes[r + 1][c]) {
            if (grid[r + 1][c] == 'U') {
                escapes[r + 1][c] = true;
                q.push({r + 1, c});
            } else if (grid[r + 1][c] == '?') {
                bad_dirs[r + 1][c]++;
                if (bad_dirs[r + 1][c] == 4) {
                    escapes[r + 1][c] = true;
                    q.push({r + 1, c});
                }
            }
        }
        if (r - 1 >= 0 && !escapes[r - 1][c]) {
            if (grid[r - 1][c] == 'D') {
                escapes[r - 1][c] = true;
                q.push({r - 1, c});
            } else if (grid[r - 1][c] == '?') {
                bad_dirs[r - 1][c]++;
                if (bad_dirs[r - 1][c] == 4) {
                    escapes[r - 1][c] = true;
                    q.push({r - 1, c});
                }
            }
        }
        if (c + 1 < m && !escapes[r][c + 1]) {
            if (grid[r][c + 1] == 'L') {
                escapes[r][c + 1] = true;
                q.push({r, c + 1});
            } else if (grid[r][c + 1] == '?') {
                bad_dirs[r][c + 1]++;
                if (bad_dirs[r][c + 1] == 4) {
                    escapes[r][c + 1] = true;
                    q.push({r, c + 1});
                }
            }
        }
        if (c - 1 >= 0 && !escapes[r][c - 1]) {
            if (grid[r][c - 1] == 'R') {
                escapes[r][c - 1] = true;
                q.push({r, c - 1});
            } else if (grid[r][c - 1] == '?') {
                bad_dirs[r][c - 1]++;
                if (bad_dirs[r][c - 1] == 4) {
                    escapes[r][c - 1] = true;
                    q.push({r, c - 1});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!escapes[i][j]) ans++;
        }
    }

    cout << ans << "\n";

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

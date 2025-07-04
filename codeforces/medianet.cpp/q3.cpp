#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;

// Helper structure for cell coordinates
struct Cell {
    int x, y;
};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> comp(N, vector<int>(N, -1));
    unordered_set<int> unique_values;
    vector<Cell> cells;

    // Input and collect unique values and unblocked cells
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            if (A[i][j] != -1) {
                unique_values.insert(A[i][j]);
                cells.push_back({i, j});
            }
        }
    }

    // Step 1: Label connected components
    int comp_id = 0;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for (const auto& cell : cells) {
        int i = cell.x, j = cell.y;
        if (comp[i][j] != -1) continue;
        queue<Cell> q;
        q.push({i, j});
        comp[i][j] = comp_id;
        while (!q.empty()) {
            Cell cur = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = cur.x + dx[d], nj = cur.y + dy[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && A[ni][nj] != -1 && comp[ni][nj] == -1) {
                    comp[ni][nj] = comp_id;
                    q.push({ni, nj});
                }
            }
        }
        ++comp_id;
    }

    // Step 2: For each value, store per-component sum and count
    // value -> component -> (count, sum)
    unordered_map<int, unordered_map<int, pair<int, long long>>> value_comp_info;
    for (const auto& cell : cells) {
        int i = cell.x, j = cell.y;
        int v = A[i][j];
        int cid = comp[i][j];
        value_comp_info[v][cid].first += 1;
        value_comp_info[v][cid].second = (value_comp_info[v][cid].second + v) % MOD;
    }

    // Step 3: For each value, precompute all its multiples present in the matrix
    unordered_map<int, vector<int>> multiples_map;
    vector<int> unique_vals_vec(unique_values.begin(), unique_values.end());
    sort(unique_vals_vec.begin(), unique_vals_vec.end());
    for (int v : unique_vals_vec) {
        for (int mul = 2; ; ++mul) {
            long long mval = 1LL * v * mul;
            if (mval > 1e6) break;
            if (unique_values.count((int)mval)) {
                multiples_map[v].push_back((int)mval);
            }
        }
    }

    // Step 4: For each (value, component), sum sed-values efficiently
    long long total = 0;
    for (int v : unique_vals_vec) {
        for (const auto& [cid, cnt_sum] : value_comp_info[v]) {
            int count = cnt_sum.first;
            // For each multiple of v present in the matrix
            for (int mval : multiples_map[v]) {
                for (const auto& [other_cid, other_cnt_sum] : value_comp_info[mval]) {
                    if (other_cid == cid) continue;
                    long long contrib = (1LL * count * other_cnt_sum.second) % MOD;
                    total = (total + contrib) % MOD;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}

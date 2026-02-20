#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int n, m;

// Helper function to generate all valid next_masks for the next column
void generate_next_masks(int current_mask, int row, int next_mask, vector<int>& next_masks) {
    // Base case: We have processed all rows in the current column
    if (row == n) {
        next_masks.push_back(next_mask);
        return;
    }

    // Case 1: The current cell is already filled by a domino from the previous column
    if ((current_mask & (1 << row)) != 0) {
        // Move to the next row, nothing pokes into the next column from here
        generate_next_masks(current_mask, row + 1, next_mask, next_masks);
    } 
    else {
        // Case 2a: Place a horizontal domino
        // It fills current cell and pokes into the next column (set bit in next_mask)
        generate_next_masks(current_mask, row + 1, next_mask | (1 << row), next_masks);

        // Case 2b: Place a vertical domino
        // It requires the current cell AND the cell below it to be empty
        if (row + 1 < n && (current_mask & (1 << (row + 1))) == 0) {
            // It doesn't poke into the next column, so next_mask bits remain 0. Skip 2 rows.
            generate_next_masks(current_mask, row + 2, next_mask, next_masks);
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    // dp[i][mask] = number of ways to fill first i columns with 'mask' poking into column i+1
    // Size: (m + 1) x (2^n)
    vector<vector<long long>> dp(m + 1, vector<long long>(1 << n, 0));
    
    // Base case: 1 way to have an empty grid of 0 columns
    dp[0][0] = 1;

    // Iterate through each column
    for (int i = 0; i < m; ++i) {
        // Iterate through all possible masks for the current column
        for (int mask = 0; mask < (1 << n); ++mask) {
            // Optimization: If current state has 0 ways to be reached, skip it
            if (dp[i][mask] == 0) continue;

            vector<int> next_masks;
            // Generate all valid transitions for the next column
            generate_next_masks(mask, 0, 0, next_masks);

            // Add the current ways to the next column's states
            for (int next_mask : next_masks) {
                dp[i + 1][next_mask] = (dp[i + 1][next_mask] + dp[i][mask]) % MOD;
            }
        }
    }

    // The answer is the number of ways to fill m columns with NO dominoes poking out
    cout << dp[m][0] << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// --- Segment Tree Implementation ---
struct SegmentTree {
    int size;
    vector<int> tree;

    // Initialize the segment tree with size n
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    // Update function: adds value 'v' to index 'i'
    // This adds to the existing value because multiple subsequences 
    // might end with the same value rank.
    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = (tree[x] + v) % MOD;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]) % MOD;
    }

    // Helper wrapper for update
    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    // Query function: sums values in range [l, r)
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        int s1 = query(l, r, 2 * x + 1, lx, m);
        int s2 = query(l, r, 2 * x + 2, m, rx);
        return (s1 + s2) % MOD;
    }

    // Helper wrapper for query
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    // Optimization for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // --- Step 1: Coordinate Compression ---
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    // Remove duplicates to get unique ranks
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    // --- Step 2: DP with Segment Tree ---
    SegmentTree st;
    st.init(sorted_a.size() + 1); // Size based on unique elements

    for (int x : a) {
        // Find the rank of the current element (0-based index)
        // lower_bound finds the first element >= x
        int rank = lower_bound(sorted_a.begin(), sorted_a.end(), x) - sorted_a.begin();
        
        // Query sum of subsequences ending with values smaller than current rank
        // Range: [0, rank)
        long long count = st.query(0, rank);
        
        // Current increasing subsequences ending here = previous_sum + 1 (for itself)
        long long current_ways = (count + 1) % MOD;
        
        // Update the tree at position 'rank' with the new ways found
        st.update(rank, current_ways);
    }

    // The answer is the sum of all counts in the tree (range [0, total_unique])
    cout << st.query(0, sorted_a.size()) << endl;

    return 0;
}
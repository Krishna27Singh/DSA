#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 200005;

int n;
int h[MAXN];
int L[MAXN], R[MAXN];
int dp[MAXN];
int tree[4 * MAXN];

// Segment Tree: Point Update
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Segment Tree: Range Maximum Query
int query(int node, int start, int end, int l, int r) {
    // If query range is invalid or completely outside the node's range
    if (r < start || end < l || l > r) {
        return 0;
    }
    // If the node's range is completely inside the query range
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(p1, p2);
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    vector<pair<int, int>> mountains;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        mountains.push_back({h[i], i});
    }

    // 1. Calculate L[i]: Nearest mountain to the left that is >= h[i]
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            st.pop();
        }
        L[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty()) st.pop();

    // 2. Calculate R[i]: Nearest mountain to the right that is >= h[i]
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && h[st.top()] < h[i]) {
            st.pop();
        }
        R[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    // 3. Sort mountains primarily by height ascending
    sort(mountains.begin(), mountains.end());

    int max_visited = 0;

    // 4. Process mountains and calculate DP
    for (auto& m : mountains) {
        int u = m.second; // original index
        
        // Query the maximum DP value in the valid left and right ranges
        int left_max = query(1, 1, n, L[u] + 1, u - 1);
        int right_max = query(1, 1, n, u + 1, R[u] - 1);
        
        // DP transition
        dp[u] = 1 + max(left_max, right_max);
        
        // Update the segment tree and track the global maximum
        update(1, 1, n, u, dp[u]);
        max_visited = max(max_visited, dp[u]);
    }

    // 5. Output the result
    cout << max_visited << "\n";

    return 0;
}
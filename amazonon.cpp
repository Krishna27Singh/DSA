#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class SparseTable {
    vector<vector<int> > st;
    vector<int> log;

public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int max_log = 32 - __builtin_clz(n);
        st.assign(n, vector<int>(max_log));
        log.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
        for (int i = 0; i < n; i++) st[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getMax(int l, int r) {
        if (l > r) return INT_MIN;
        int j = log[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

long long countPromotionalPeriods(const vector<int>& orders) {
    int n = orders.size();
    SparseTable st(orders);
    long long count = 0;

    for (int i = 0; i <= n - 3; ++i) {
        for (int j = i + 2; j < n; ++j) {
            int minEnds = min(orders[i], orders[j]);
            int maxMiddle = st.getMax(i + 1, j - 1);

            if (minEnds > maxMiddle) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> orders(n);
    for (int i = 0; i < n; ++i) {
        cin >> orders[i];
    }
    cout << countPromotionalPeriods(orders) << endl;
    return 0;
}

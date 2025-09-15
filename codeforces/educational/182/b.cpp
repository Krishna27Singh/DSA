#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Function to compute cost of permutation
int computeCost(vector<int>& a) {
    int n = a.size();
    int l = 0;
    while (l < n - 1 && a[l] <= a[l + 1]) l++;
    if (l == n - 1) return 0;  // already sorted

    int r = n - 1;
    while (r > 0 && a[r - 1] <= a[r]) r--;

    int minVal = *min_element(a.begin() + l, a.begin() + r + 1);
    int maxVal = *max_element(a.begin() + l, a.begin() + r + 1);

    while (l > 0 && a[l - 1] > minVal) l--;
    while (r < n - 1 && a[r + 1] < maxVal) r++;

    return r - l + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        set<int> present;
        vector<int> zeroPositions;

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] == 0) {
                zeroPositions.push_back(i);
            } else {
                present.insert(p[i]);
            }
        }

        // Get missing numbers
        vector<int> missing;
        for (int i = 1; i <= n; ++i) {
            if (!present.count(i)) {
                missing.push_back(i);
            }
        }

        // Sort missing in descending to place large numbers early
        sort(missing.begin(), missing.end(), greater<int>());

        // Place them greedily
        for (int i = 0; i < zeroPositions.size(); ++i) {
            p[zeroPositions[i]] = missing[i];
        }

        // Compute cost
        int cost = computeCost(p);
        cout << cost << '\n';
    }

    return 0;
}

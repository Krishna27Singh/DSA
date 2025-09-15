#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1); // 1-based indexing
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        // Compute prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }
        
        bool found = false;
        for (int l = 1; l < n && !found; ++l) {
            for (int r = l + 1; r < n && !found; ++r) {
                int s1 = (prefix[l] - prefix[0]) % 3;
                int s2 = (prefix[r] - prefix[l]) % 3;
                int s3 = (prefix[n] - prefix[r]) % 3;
                // Check if all same or all different
                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)) {
                    cout << l << " " << r << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "0 0" << endl;
        }
    }
    return 0;
}

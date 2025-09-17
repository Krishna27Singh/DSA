#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    int l = 0;
    while (l < n - 1 && a[l] <= a[l + 1]){
        l++;
    }
    if (l==n - 1) return 0;  

    int r = n - 1;
    while (r > 0 && a[r - 1] <= a[r]){
        r--;
    }

    int minVal = *min_element(a.begin() + l, a.begin() + r + 1);
    int maxVal = *max_element(a.begin() + l, a.begin() + r + 1);

    while (l > 0 && a[l - 1] > minVal){
        l--;
    }
    while (r < n - 1 && a[r + 1] < maxVal){
        r++;
    }

    return r - l + 1;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> p(n);
        set<int> curr;
        vector<int> zero;

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] == 0) {
                zero.push_back(i);
            } else {
                curr.insert(p[i]);
            }
        }

        vector<int> missing;
        for (int i = 1; i <= n; ++i) {
            if (!curr.count(i)) {
                missing.push_back(i);
            }
        }

        sort(missing.begin(), missing.end(), greater<int>());

        for (int i = 0; i < zero.size(); ++i) {
            p[zero[i]] = missing[i];
        }

        int cost = solve(p);
        cout<< cost <<endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) {
        int n;
        ll X;
        cin >> n >> X;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end()); 

        ll S = 0;           
        ll points = 0;   
        vector<ll> order;   

        int l = 0, r = n - 1;
        while (l <= r) {
            ll rem = S % X;
            if (a[r] + rem >= X) {
                S += a[r];
                points += a[r];
                order.push_back(a[r]);
                --r;
            } else {
                S += a[l];
                order.push_back(a[l]);
                ++l;
            }
        }

        cout << points << '\n';
        for (int i = 0; i < (int)order.size(); ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }
    return 0;
}

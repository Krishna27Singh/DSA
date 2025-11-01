#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<long long> a(n);
        for(int i = 0; i<n; ++i){
            cin >> a[i];
        }

        long long total_gcd = a[0];
        for (int i = 1; i < n; ++i){}
            g = gcd(g, a[i]);
    }

        long long ans = -1;
        for (long long x = 2; x <= 1000; x++) { 
            if (gcd(g, x) == 1) {
                ans = x;
                break;
            }
        }

        cout << ans <<endl;
    }
}

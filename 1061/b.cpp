#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin>>tc;
    while (tc--) {
        int n, q;
        cin >>n >> q;
        string s;
        cin>>s;
        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

        int count_b = 0;
        for (char c : s) if (c == 'B') ++count_b;

        for (int i = 0; i < q; ++i) {
            long long a = queries[i];
            if (count_b == 0) {
                cout << a <<endl;
                continue;
            }
            int value = 0;               
            long long seconds = 0;
            while (a > 0) {
                if (s[value] == 'A') {
                    --a;
                } else { 
                    a /= 2;
                }
                ++seconds;
                value = (value + 1);
                if (value == n) value = 0;
            }
            cout << seconds <<endl;
        }
    }
    return 0;
}

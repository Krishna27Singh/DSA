#include <iostream>
using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;

        long long rows_leftover = max(a, n - a);
        long long cols_leftover = max(b, m - b);

        long long turns = rows_leftover + cols_leftover;

        cout << turns << "\n";
    }

    return 0;
}

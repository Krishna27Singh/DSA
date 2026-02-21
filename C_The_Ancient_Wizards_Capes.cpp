#include <iostream>
using namespace std;

bool validar(vector<int> &x, int n, vector<int> &a) {
    int visibles = 0;

    for (int i = 1; i <= n; i++) {
        if (x[i] == 1)
            visibles++;
    }

    if (visibles != a[1])
        return false;

    for (int i = 1; i < n; i++) {
        if (x[i] == 1 && x[i+1] == 1) {
            visibles--;
        }
        else if (x[i] == 0 && x[i+1] == 0) {
            visibles++;
        }

        if (a[i+1] != visibles)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> sol1(n+1), sol2(n+1);
        sol1[1] = 0;
        sol2[1] = 1;

        bool valid = true;

        for (int i = 1; i < n; i++) {
            int diff = a[i+1] - a[i];

            if (abs(diff) > 1) {
                valid = false;
                break;
            }

            if (diff == 0) {
                sol1[i+1] = 1 - sol1[i];
                sol2[i+1] = 1 - sol2[i];
            }
            else { 
                sol1[i+1] = sol1[i];
                sol2[i+1] = sol2[i];
            }
        }

        if (!valid) {
            cout << 0 << "\n";
            continue;
        }

        int count = 0;

        if (validar(sol1, n, a))
            count++;

        if (validar(sol2, n, a))
            count++;

        cout << count << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<bool> used(N, false);
    vector<int> X(20, 0);

    for (int i = 1; i <= 20; ++i) {
        int mask = (1 << (20 - i)) - 1;
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (!used[j] && (A[j] & mask) == 0) {
                ++count;
                used[j] = true; // Mark as used for future i
            }
        }
        X[i - 1] = count;
    }

    for (int x : X) cout << x << " ";
    cout << endl;
    return 0;
}

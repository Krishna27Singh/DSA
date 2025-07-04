#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Helper function to count set bits
int bit_count(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int count_unique_xors(const vector<int>& A) {
    const int MAX_A = 100;
    const int MAX_XOR = 127; // 7 bits for 0-100
    vector<vector<unordered_set<int> > > dp(MAX_A + 1, vector<unordered_set<int> >(MAX_XOR + 1));
    unordered_set<int> result;

    for (int num : A) {
        // Start new subsequence with this number
        dp[num][num].insert(num);
        result.insert(num);

        // Extend previous subsequences
        for (int prev = 1; prev <= num; ++prev) {
            for (int x = 0; x <= MAX_XOR; ++x) {
                for (int prev_xor : dp[prev][x]) {
                    int new_xor = prev_xor ^ num;
                    if (bit_count(x) <= bit_count(num)) {
                        dp[num][new_xor].insert(new_xor);
                        result.insert(new_xor);
                    }
                }
            }
        }
    }
    return result.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& x : A) cin >> x;
    cout << count_unique_xors(A) << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 1000005;
int min_prime[MAXA];
int base_val[MAXA];

// Precompute the smallest prime factor and the base for each number up to 10^6
void precompute() {
    for (int i = 2; i < MAXA; i++) {
        min_prime[i] = i;
    }
    for (int i = 2; i * i < MAXA; i++) {
        if (min_prime[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
    
    base_val[1] = 1;
    for (int i = 2; i < MAXA; i++) {
        int temp = i;
        int p = min_prime[temp];
        bool is_prime_power = true;
        
        while (temp > 1) {
            if (min_prime[temp] != p) {
                is_prime_power = false;
                break;
            }
            temp /= min_prime[temp];
        }
        
        // If it's a prime power, its base is 'p'. If it has >= 2 distinct primes, flag as -1.
        if (is_prime_power) {
            base_val[i] = p;
        } else {
            base_val[i] = -1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool is_sorted_initially = true;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i-1]) {
            is_sorted_initially = false;
        }
    }
    
    // Condition 1: If it's already sorted, Bob wins automatically.
    if (is_sorted_initially) {
        cout << "Bob\n";
        return;
    }
    
    // Check if there's any element composed of more than one distinct prime factor
    bool all_prime_powers = true;
    for (int i = 0; i < n; i++) {
        if (base_val[a[i]] == -1) {
            all_prime_powers = false;
            break;
        }
    }
    
    // Condition 2: If there's an element that's not a prime power, Alice traps Bob and wins.
    if (!all_prime_powers) {
        cout << "Alice\n";
        return;
    }
    
    // Condition 3: Verify if the prime power bases are strictly non-decreasing
    bool bases_sorted = true;
    for (int i = 1; i < n; i++) {
        if (base_val[a[i]] < base_val[a[i-1]]) {
            bases_sorted = false;
            break;
        }
    }
    
    if (bases_sorted) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    // Optimize standard I/O operations for performance 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
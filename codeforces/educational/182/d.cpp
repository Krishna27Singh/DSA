#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

const int MAX_X = 10000;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll y;
        cin >> n >> y;

        vector<int> c(n);
        unordered_map<int, int> original_freq;
        for (int &price : c) {
            cin >> price;
            original_freq[price]++;
        }

        ll max_profit = LLONG_MIN;

        for (int x = 2; x <= MAX_X; ++x) {
            unordered_map<int, int> freq_copy = original_freq;
            unordered_map<int, int> new_price_freq;
            ll sum = 0;

            for (int i = 0; i < n; ++i) {
                int new_price = (c[i] + x - 1) / x; 
                sum += new_price;
                new_price_freq[new_price]++;
            }

            ll new_tag_cost = 0;
            for (auto &[price, count] : new_price_freq) {
                int available = freq_copy[price];
                int need_to_print = max(0, count - available);
                new_tag_cost += 1LL * need_to_print * y;
            }

            ll profit = sum - new_tag_cost;
            max_profit = max(max_profit, profit);
        }

        cout << max_profit <<endl;
    }

    return 0;
}

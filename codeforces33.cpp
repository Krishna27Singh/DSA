#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Extract distinct values (input is sorted)
        vector<int> values;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i-1]) {
                values.push_back(a[i]);
            }
        }
        
        int result = 0;
        int i = 0;
        
        // Group into consecutive sequences
        while (i < values.size()) {
            int j = i;
            while (j < values.size() && values[j] == values[i] + (j - i)) {
                j++;
            }
            // [i, j) is a consecutive sequence
            int length = j - i;
            result += (length + 1) / 2;  // ceil(length / 2)
            i = j;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}

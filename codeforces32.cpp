
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        int count0 = 0;
        for (char c : s) {
            if (c == '0') count0++;
        }
        
        int count1 = n - count0;
        
        if (count0 >= n/2 - k && count1 >= n/2 - k && 
            (count0 + k) % 2 == (n/2) % 2) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }
    
    return 0;
}
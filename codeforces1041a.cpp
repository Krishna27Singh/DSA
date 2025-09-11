#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> values;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != -1)
                values.insert(a[i]);
        }

        if (values.size() == 0) {
            cout << "YES"<<endl;
        }
        else if (values.size() == 1) {
            int val = *values.begin();
            if (val == 0)
                cout << "NO"<<endl;  
            else
                cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }

    return 0;
}

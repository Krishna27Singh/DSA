
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int year = stoi(s); // Convert the string to an integer
        
        // Compute the square root of the year
        int root = sqrt(year);

        if (root * root != year) {
            // Not a perfect square
            cout << -1 << endl;
        } else {
            // Find valid a and b such that a + b = root
            for (int a = 0; a <= root; ++a) {
                int b = root - a;
                if (b >= 0) {
                    cout << a << " " << b << endl;
                    break;
                }
            }
        }
    }

    return 0;
}


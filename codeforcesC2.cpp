// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int minOperationsToFashionable(vector<int>& arr) {
//     int n = arr.size();

//     // Case 1: If there's only one element
//     if (n == 1) {
//         return 0;
//     }

//     // Case 2: If there are two elements
//     if (n == 2) {
//         int sum = arr[0] + arr[1];
//         return (sum % 2 == 0) ? 0 : 1;
//     }

//     // Case 3: More than two elements
//     int count1 = 0, count2 = 0;

//     // Copy array to avoid modifying the original
//     vector<int> temp = arr;

//     // Sort the array to easily access min and max
//     sort(temp.begin(), temp.end());

//     // Option 1: Remove the minimum element until min + max is divisible by 2
//     vector<int> copy1 = temp;
//     while (!copy1.empty() && (copy1.front() + copy1.back()) % 2 != 0) {
//         copy1.erase(copy1.begin()); // Remove the smallest element
//         count1++;
//     }

//     // Option 2: Remove the maximum element until min + max is divisible by 2
//     vector<int> copy2 = temp;
//     while (!copy2.empty() && (copy2.front() + copy2.back()) % 2 != 0) {
//         copy2.pop_back(); // Remove the largest element
//         count2++;
//     }

//     // Return the minimum of the two counts
//     return min(count1, count2);
// }

// int main() {
//     int t;
//     cin >> t; // Number of test cases

//     while (t--) {
//         int n;
//         cin >> n; // Size of the array
//         vector<int> arr(n);

//         for (int i = 0; i < n; ++i) {
//             cin >> arr[i];
//         }

//         // Output the result for the current test case
//         cout << minOperationsToFashionable(arr) << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// string solve(string s) {
//     int n = s.length();
    
//     // Find all positions of '(' and ')'
//     vector<int> open, close;
//     for (int i = 0; i < n; i++) {
//         if (s[i] == '(') open.push_back(i);
//         else close.push_back(i);
//     }
    
//     // Try removing each pair of '(' and ')'
//     for (int op : open) {
//         for (int cl : close) {
//             // Check if string becomes unbalanced after removing positions op and cl
//             int balance = 0;
//             bool valid = true;
            
//             for (int i = 0; i < n; i++) {
//                 if (i == op || i == cl) continue; // Skip removed characters
                
//                 if (s[i] == '(') balance++;
//                 else balance--;
                
//                 if (balance < 0) {
//                     valid = false;
//                     break;
//                 }
//             }
            
//             // If balance goes negative OR final balance != 0, string is unbalanced
//             if (!valid || balance != 0) {
//                 return "YES";
//             }
//         }
//     }
    
//     return "NO";
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         cin >> s;
//         cout << solve(s) << endl;
//     }
//     return 0;
// }#include <iostream>

// #include<iostream>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while(t--) {
//         string s;
//         cin >> s;
//         int n = s.length();
        
//         // Precompute hasCloseAfter[i] = true if there's any ')' after position i
//         vector<bool> hasCloseAfter(n, false);
//         bool seenClose = false;
//         for(int i = n - 1; i >= 0; i--) {
//             hasCloseAfter[i] = seenClose;
//             if(s[i] == ')') {
//                 seenClose = true;
//             }
//         }
        
//         int balance = 0;
//         bool seenOpen = false;
//         bool canMakeUnbalanced = false;
        
//         for(int i = 0; i < n; i++) {
//             if(s[i] == '(') {
//                 balance++;
//                 seenOpen = true;
//             } else {
//                 balance--;
//             }
            
//             // If balance becomes 0 and we've seen an opening bracket before
//             // and there's a closing bracket after current position
//             if(balance == 0 && seenOpen && hasCloseAfter[i]) {
//                 canMakeUnbalanced = true;
//                 break;
//             }
//         }
        
//         cout << (canMakeUnbalanced ? "YES" : "NO") << "\n";
//     }
    
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];

        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

        // Forward pass: track possible height range at each step
        int minH = 0, maxH = 0;
        vector<int> minHs(n + 1), maxHs(n + 1);
        minHs[0] = maxHs[0] = 0;
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            int newMin, newMax;
            if (d[i] == 0) {
                newMin = minH;
                newMax = maxH;
            } else if (d[i] == 1) {
                newMin = minH + 1;
                newMax = maxH + 1;
            } else { // d[i] == -1
                newMin = minH;
                newMax = maxH + 1;
            }
            newMin = max(newMin, l[i]);
            newMax = min(newMax, r[i]);
            if (newMin > newMax) {
                possible = false;
                break;
            }
            minH = newMin;
            maxH = newMax;
            minHs[i + 1] = minH;
            maxHs[i + 1] = maxH;
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        // Backward pass: reconstruct d (try 0 first, then 1)
        vector<int> ans(n);
        int h = maxHs[n];
        for (int i = n - 1; i >= 0; --i) {
            if (d[i] != -1) {
                ans[i] = d[i];
                h -= d[i];
            } else {
                // Try 0 first
                if (minHs[i] <= h && h <= maxHs[i]) {
                    ans[i] = 0;
                } else if (minHs[i] <= h - 1 && h - 1 <= maxHs[i]) {
                    ans[i] = 1;
                    h -= 1;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; ++i) cout << ans[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}

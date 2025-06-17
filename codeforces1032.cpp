// #include <iostream>
// #include <string>
// using namespace std;

// bool solve(const string& s) {
//     int n = s.size();
//     // Check if the first and last character are the same
//     if (s[0] == s[n-1]) return true;
//     // Check prefix and suffix
//     for (int len = 1; len < n - 1; ++len) {
//         string a = s.substr(0, len);
//         string c = s.substr(len+1);
//         string b = s.substr(len, 1);
//         if ((a + c).find(b) != string::npos) return true;
//     }
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         string s;
//         cin >> n >> s;
//         cout << (solve(s) ? "Yes" : "No") << '\n';
//     }
//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main(){

//     int tc; cin>>tc;
//     while(tc--){
//         int n, s; cin>>n>>s;
//         vector<int> x(n);
//         for(int i = 0; i<n; i++) cin>>x[i];


//     }

//     return 0;
// }

// #include <iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, s;
//         cin>>n>>s;
//         vector<int> x(n);
//         for (int i = 0; i < n; i++) cin >> x[i];
        
//         vector<int> newx = x;
//         sort(newx.begin(), newx.end());
//         int min_position = newx[0];
//         int max_position = newx[newx.size()-1];
        
//         int answer1 = abs(s - min_position) + (max_position - min_position);
        
//         int answer2 = abs(s - max_position) + (max_position - min_position);
        
//         cout << min(answer1, answer2)<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// bool fast_check(const string& s) {
//     int n = s.size();
//     vector<int> left(26, 0), right(26, 0);

//     // Count occurrences in prefix (excluding last char)
//     for (int i = 0; i < n-1; ++i)
//         left[s[i] - 'a']++;

//     // Count occurrences in suffix (excluding first char)
//     for (int i = 1; i < n; ++i)
//         right[s[i] - 'a']++;

//     // For each position in the middle, check if char exists in prefix or suffix
//     for (int i = 1; i < n-1; ++i) {
//         char ch = s[i];
//         // Remove current position from left/right to avoid overlap
//         left[s[i-1] - 'a']--;
//         right[s[i] - 'a']--;
//         if (left[ch - 'a'] > 0 || right[ch - 'a'] > 0)
//             return true;
//     }
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         string s;
//         cin >> n >> s;
//         cout << (fast_check(s) ? "Yes" : "No") << endl;
//     }
//     return 0;
// }

// // #include <iostream>
// // #include <string>
// // using namespace std;

// // bool solve(const string& s) {
// //     int n = s.size();
    
// //     for (int i = 1; i < n-1; ++i) {
// //         for (int j = i+1; j < n; ++j) {
// //             int b_len = j - i;
            
// //             // Case 1: b is substring of a
// //             for (int k = 0; k <= i - b_len; ++k) {
// //                 bool match = true;
// //                 for (int l = 0; l < b_len; ++l) {
// //                     if (s[k + l] != s[i + l]) {
// //                         match = false;
// //                         break;
// //                     }
// //                 }
// //                 if (match) return true;
// //             }
            
// //             // Case 2: b is substring of c
// //             for (int k = j; k <= n - b_len; ++k) {
// //                 bool match = true;
// //                 for (int l = 0; l < b_len; ++l) {
// //                     if (s[k + l] != s[i + l]) {
// //                         match = false;
// //                         break;
// //                     }
// //                 }
// //                 if (match) return true;
// //             }
            
// //             // Case 3: b spans across end of a and start of c
// //             for (int k = 1; k < b_len && k <= i && b_len - k <= n - j; ++k) {
// //                 bool match = true;
// //                 // Check if last k chars of a match first k chars of b
// //                 for (int l = 0; l < k; ++l) {
// //                     if (s[i - k + l] != s[i + l]) {
// //                         match = false;
// //                         break;
// //                     }
// //                 }
// //                 if (match) {
// //                     // Check if first (b_len-k) chars of c match last (b_len-k) chars of b
// //                     for (int l = 0; l < b_len - k; ++l) {
// //                         if (s[j + l] != s[i + k + l]) {
// //                             match = false;
// //                             break;
// //                         }
// //                     }
// //                     if (match) return true;
// //                 }
// //             }
// //         }
// //     }
// //     return false;
// // }

// // int main() {
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         int n;
// //         string s;
// //         cin >> n >> s;
// //         cout << (solve(s) ? "Yes" : "No") << endl;
// //     }
// //     return 0;
// // }

// #include <iostream>
// #include <string>
// using namespace std;

// bool check(const string& s) {
//     int n = s.size();
//     for (int i = 1; i < n - 1; ++i) {
//         if (s.substr(0, i).find(s[i]) != string::npos || 
//             s.substr(i + 1).find(s[i]) != string::npos) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n;
//         string s;
//         cin >> n >> s;
//         cout << (check(s) ? "Yes" : "No") << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<vector<int> >& a, int n, int m) {
    vector<int> row_max(n, 0), col_max(m, 0);
    // Find max in each row and column
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            row_max[i] = max(row_max[i], a[i][j]);
            col_max[j] = max(col_max[j], a[i][j]);
        }
    // Find top two max values in rows and columns
    vector<pair<int, int> > row_vals, col_vals;
    for (int i = 0; i < n; ++i) row_vals.push_back({row_max[i], i});
    for (int j = 0; j < m; ++j) col_vals.push_back({col_max[j], j});
    sort(row_vals.rbegin(), row_vals.rend());
    sort(col_vals.rbegin(), col_vals.rend());

    int answer = 1e9;
    // Try all combinations of top two max rows and columns
    for (int x = 0; x < min(2, n); ++x) {
        for (int y = 0; y < min(2, m); ++y) {
            int r = row_vals[x].second;
            int c = col_vals[y].second;
            int local_max = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    int val = a[i][j];
                    if (i == r || j == c) val--;
                    local_max = max(local_max, val);
                }
            answer = min(answer, local_max);
        }
    }
    return answer;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        cout << solve(a, n, m) << endl;
    }
    return 0;
}

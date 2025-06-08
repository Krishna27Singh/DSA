// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
        
//         vector<int> result(n);
        
//         if (n == 1) {
//             result[0] = 1;
//         } else if (n == 2) {
//             result[0] = 1;
//             result[1] = 2;
//         } else {
//             // Pattern: [1, n, n-1, n-2, ..., 3, 2]
//             result[0] = 1;
//             for (int i = 1; i < n; i++) {
//                 result[i] = n - i + 1;
//             }
// //         }
        
// //         for (int i = 0; i < n; i++) {
// //             cout << result[i];
// //             if (i < n-1) cout << " ";
// //         }
// //         cout << "\n";
// //     }
    
// //     return 0;
// // }


// #include <iostream>
// #include<unordered_map>
// #include<set>
// #include<unordered_set>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
        
//         if (n == 1) {
//             cout << 1 << "\n";
//             continue;
//         }
        
//         int segments = 1;
//         unordered_set<int> current_segment;
        
//         for (int i = 0; i < n - 1; i++) {
//             current_segment.insert(a[i]);
            
//             // Check if we can end current segment at position i
//             // by verifying all current elements appear in suffix
//             unordered_set<int> suffix_elements;
//             for (int j = i + 1; j < n; j++) {
//                 suffix_elements.insert(a[j]);
//             }
            
//             bool can_split = true;
//             for (int elem : current_segment) {
//                 if (suffix_elements.count(elem) == 0) {
//                     can_split = false;
//                     break;
//                 }
//             }
            
//             if (can_split) {
//                 segments++;
//                 current_segment.clear();
//             }
//         }
        
//         cout << segments << "\n";
//     }
    
//     return 0;
// }


// #include <iostream>
// #include<map>
// #include<unordered_map>
// #include<unordered_set>
// #include<vector>
// #include<algorithm>

// // using namespace std;

// // vector<int> a;
// // int n;
// // map<pair<int, vector<int> >, int> memo;

// // int solve(int start, vector<int> required_elements) {
// //     if (start >= n) return 0;
    
// //     sort(required_elements.begin(), required_elements.end());
    
// //     auto key = make_pair(start, required_elements);
// //     if (memo.count(key)) return memo[key];
    
// //     int result = 0;
// //     unordered_set<int> current_segment;
// //     unordered_set<int> required_set(required_elements.begin(), required_elements.end());
    
// //     for (int end = start; end < n; end++) {
// //         current_segment.insert(a[end]);
        
// //         // Check if current segment contains all required elements
// //         bool satisfies_constraint = true;
// //         for (int elem : required_set) {
// //             if (current_segment.count(elem) == 0) {
// //                 satisfies_constraint = false;
// //                 break;
// //             }
// //         }
        
// //         if (!satisfies_constraint) continue;
        
// //         if (end == n - 1) {
// //             // Last segment
// //             result = max(result, 1);
// //         } else {
// //             // Pass current segment's elements as requirement for next segment
// //             vector<int> next_required(current_segment.begin(), current_segment.end());
// //             result = max(result, 1 + solve(end + 1, next_required));
// //         }
// //     }
    
// //     return memo[key] = result;
// // }

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
    
// //     int t;
// //     cin >> t;
    
// //     while (t--) {
// //         cin >> n;
// //         a.resize(n);
// //         memo.clear();
        
// //         for (int i = 0; i < n; i++) {
// //             cin >> a[i];
// //         }
        
// //         cout << solve(0, vector<int>()) << "\n";

// //     }
    
// //     return 0;
// // }
// // #include <iostream>
// // #include <vector>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
        
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
        
//         // Special case: single element
//         if (n == 1) {
//             cout << "YES\n";
//             continue;
//         }
        
//         // Check if array forms arithmetic progression
//         long long d = a[1] - a[0];
//         bool isAP = true;
        
//         for (int i = 2; i < n; i++) {
//             if (a[i] - a[i-1] != d) {
//                 isAP = false;
//                 break;
//             }
//         }
        
//         if (!isAP) {
//             cout << "NO\n";
//             continue;
//         }
        
//         // Check divisibility condition
//         if ((a[0] - d) % (n + 1) != 0) {
//             cout << "NO\n";
//             continue;
//         }
        
//         // Calculate number of operations needed
//         long long y = (a[0] - d) / (n + 1);
//         long long x = d + y;
        
//         // Check if both are non-negative
//         if (x >= 0 && y >= 0) {
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
//         }
//     }
    
//     return 0;
// // }
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <unordered_map>
// #include <functional> // For std::function

// using namespace std;

// template <typename F>
// struct y_combinator {
//     F f;
//     template <typename... Args>
//     auto operator()(Args&&... args) -> decltype(f(std::ref(*this), std::forward<Args>(args)...)) {
//         return f(std::ref(*this), std::forward<Args>(args)...);
//     }
// };

// template <typename F>
// y_combinator<F> make_y_combinator(F f) {
//     return {std::move(f)};
// }

// int solve(vector<int>& a) {
//     int n = a.size();
//     if (n <= 1) return n;

//     vector<unordered_set<int>> suffixSets(n + 1);
//     for (int i = n - 1; i >= 0; i--) {
//         suffixSets[i] = suffixSets[i + 1];
//         suffixSets[i].insert(a[i]);
//     }

//     auto dfs = make_y_combinator([&](auto self, int start, unordered_set<int> required) -> int {
//         if (start >= n) return 0;

//         unordered_set<int> currentSegment;
//         int maxSegments = 1;

//         for (int end = start; end < n; end++) {
//             currentSegment.insert(a[end]);

//             bool containsAll = true;
//             for (int x : required) {
//                 if (currentSegment.find(x) == currentSegment.end()) {
//                     containsAll = false;
//                     break;
//                 }
//             }

//             if (containsAll) {
//                 if (end == n - 1) {
//                     maxSegments = max(maxSegments, 1);
//                 } else {
//                     const auto& remaining = suffixSets[end + 1];

//                     bool canContinue = true;
//                     for (int x : currentSegment) {
//                         if (remaining.find(x) == remaining.end()) {
//                             canContinue = false;
//                             break;
//                         }
//                     }

//                     if (canContinue) {
//                         maxSegments = max(maxSegments, 1 + self(end + 1, currentSegment));
//                     }
//                 }
//             }
//         }

//         return maxSegments;
//     });

//     return dfs(0, unordered_set<int>{});
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);

//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }

//         cout << solve(a) << "\n";
//     }

//     return 0;
// }



// #include <iostream>
// #include<unordered_map>
// #include<unordered_set>
// #include<algorithm>
// #include<vector>

// using namespace std;

// vector<unordered_set<int> > suffix;
// vector<int> a;
// int n;

// int dfs(int pos, unordered_set<int> needed) {
//     if (pos == n) return 0;
    
//     unordered_set<int> current;
//     int max_result = 1; // At minimum, take rest as one segment
    
//     for (int end = pos; end < n; end++) {
//         current.insert(a[end]);
        
//         // Check if current segment contains all needed elements from previous segment
//         bool has_all_needed = true;
//         for (unordered_set<int>::iterator it = needed.begin(); it != needed.end(); ++it) {
//             if (current.count(*it) == 0) {
//                 has_all_needed = false;
//                 break;
//             }
//         }
        
//         if (has_all_needed) {
//             if (end == n - 1) {
//                 // This is the last possible segment
//                 max_result = max(max_result, 1);
//             } else {
//                 // Check if all elements in current segment appear in remaining part
//                 bool can_continue = true;
//                 for (unordered_set<int>::iterator it = current.begin(); it != current.end(); ++it) {
//                     if (suffix[end + 1].count(*it) == 0) {
//                         can_continue = false;
//                         break;
//                     }
//                 }
                
//                 if (can_continue) {
//                     // Try making a cut here and continue recursively
//                     int result_with_cut = 1 + dfs(end + 1, current);
//                     max_result = max(max_result, result_with_cut);
//                 }
//             }
//         }
//     }
    
//     return max_result;
// }

// int solve(vector<int>& arr) {
//     a = arr;
//     n = a.size();
//     if (n <= 1) return n;
    
//     // Precompute suffix sets for efficient lookup
//     suffix.assign(n + 1, unordered_set<int>());
//     for (int i = n - 1; i >= 0; i--) {
//         suffix[i] = suffix[i + 1];
//         suffix[i].insert(a[i]);
//     }
    
//     return dfs(0, unordered_set<int>());
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
        
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
        
//         cout << solve(a) << "\n";
//     }
    
//     return 0;
// }



#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    if (n <= 1) return n;

    // Precompute suffix sets for efficiency
    vector<unordered_set<int> > suffixSets(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suffixSets[i] = suffixSets[i + 1];
        suffixSets[i].insert(a[i]);
    }

    // Recursive lambda function
    auto dfs = [&](auto& self, int start, unordered_set<int> required) -> int {
        if (start >= n) return 0;

        unordered_set<int> currentSegment;
        int maxSegments = 1; // At least one segment (entire remaining array)

        for (int end = start; end < n; end++) {
            currentSegment.insert(a[end]);

            // Check if currentSegment contains all required elements
            bool containsAll = true;
            for (int x : required) {
                if (currentSegment.find(x) == currentSegment.end()) {
                    containsAll = false;
                    break;
                }
            }

            if (containsAll) {
                if (end == n - 1) {
                    // This is the last segment
                    maxSegments = max(maxSegments, 1);
                } else {
                    // Check if currentSegment elements appear in remaining part
                    const auto& remaining = suffixSets[end + 1];

                    bool canContinue = true;
                    for (int x : currentSegment) {
                        if (remaining.find(x) == remaining.end()) {
                            canContinue = false;
                            break;
                        }
                    }

                    if (canContinue) {
                        maxSegments = max(maxSegments, 1 + self(self, end + 1, currentSegment));
                    }
                }
            }
        }

        return maxSegments;
    };

    return dfs(dfs, 0, unordered_set<int>{});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve(a) << "\n";
    }

    return 0;
}

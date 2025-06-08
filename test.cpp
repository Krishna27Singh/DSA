// // // Fully observation based question hai ye.
// // /*
// //     Logic ye hoga ki hum agar 01 and 10 ko saath rakhenge to final string 0110 banega jaha par sirf 2 hi position par different hai.
// //     Nahi to 1010 ya 0101 mein 3 position par different aa jaayega.
    
// //     Isi liye hum log pair banane ka try karenge.
// //     Pair ke liye dono mein se minimum hi consider hoga.
    
// //     Ab baaki bache hue string ko ya to starting mein ya last meib rakhna jyaada suitable hoga.
// //     Usi ke liye har character par different mil hi jaayega.
// // */

// // #include <iostream>
// // using namespace std;

// // int main() {
// //     // your code goes here
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         int x, y;
// //         cin >> x >> y;
// //         int diff = abs(x - y);
// //         int ans = min(x, y) * 2 + (diff * 2);
        
// //         // answer mein -1 karne ka logic ye hai ki hum starting ya ennding mein optimally aise rakh denge ki 0 uar 0 saath ho jaaye ya 1 aur 1 saath ho jaaye, isse ek index aur kam ho jaayega jaha par differ kar raha hai.
// //         if (diff > 0)
// //             ans -= 1;
// //         cout << ans << endl;
// //     }
// // }

// // #include<iostream>
// // using namespace std;

// // int main(){

// //     string s = "krishna";
// //     string s1 = "shalini";
// //     swap(s[0], s1[0]);
// //     cout<<s<<endl;
// //     cout<<s1;

// //     return 0;
// // }

// #include <iostream>
// #include<stack>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         string s;
//         cin >> n >> s;
        
//         vector<int> ans(n);
//         stack<int> st;
//         int num = 1;
        
//         for (int i = 0; i < n; i++) {
//             st.push(i);
            
//             // If we see '>' or reach the end, pop and assign values
//             if (i == n - 1 || s[i] == '>') {
//                 while (!st.empty()) {
//                     ans[st.top()] = num++;
//                     st.pop();
//                 }
//             }
//         }
        
//         for (int i = 0; i < n; i++) {
//             cout << ans[i];
//             if (i < n - 1) cout << " ";
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// int gcd(int a, int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// int solve(vector<int>& arr) {
//     int n = arr.size();
    
//     // Compute GCD of all elements
//     int g = arr[0];
//     for (int i = 1; i < n; i++) {
//         g = gcd(g, arr[i]);
//     }
    
//     // Count elements already equal to target
//     int count_target = 0;
//     for (int x : arr) {
//         if (x == g) count_target++;
//     }
    
//     // If all elements are already equal to target
//     if (count_target == n) return 0;
    
//     // If some elements are already equal to target
//     if (count_target > 0) return n - count_target;
    
//     // If no elements are equal to target
//     // Check if any two elements can directly create the target
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (gcd(arr[i], arr[j]) == g) {
//                 return n;  // 1 op to create target + (n-1) to convert rest
//             }
//         }
//     }
    
//     // Need 2 operations to create target, then (n-1) to convert rest
//     return n + 1;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         cout << solve(arr) << "\n";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// const int MOD = 998244353;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> p(n), q(n);
//         for (int i = 0; i < n; ++i) cin >> p[i];
//         for (int i = 0; i < n; ++i) cin >> q[i];

//         // Precompute powers of two up to n-1
//         vector<int> pow2(n);
//         pow2[0] = 1;
//         for (int i = 1; i < n; ++i) {
//             pow2[i] = (2LL * pow2[i-1]) % MOD;
//         }

//         // Precompute 2^p_j and 2^q_j
//         vector<int> pp(n), qq(n);
//         for (int i = 0; i < n; ++i) {
//             pp[i] = pow2[p[i]];
//             qq[i] = pow2[q[i]];
// //         }

// //         vector<int> res(n, 0);
// //         for (int i = 0; i < n; ++i) {
// //             int mx = 0;
// //             for (int j = 0; j <= i; ++j) {
// //                 int val = (pp[j] + qq[i-j]) % MOD;
// //                 if (val > mx) mx = val;
// //             }
// //             res[i] = mx;
// //         }

// //         for (int i = 0; i < n; ++i) {
// //             cout << res[i];
// //             if (i + 1 < n) cout << " ";
// //         }
// //         cout << "\n";
// //     }
// //     return 0;
// // }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int MOD = 998244353;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     vector<int> pow2(100005);
//     pow2[0] = 1;
//     for (int i = 1; i < 100005; ++i)
//         pow2[i] = (2LL * pow2[i-1]) % MOD;

//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> p(n), q(n);
//         for (int i = 0; i < n; ++i) cin >> p[i];
//         for (int i = 0; i < n; ++i) cin >> q[i];

//         vector<int> A(n), B(n);
//         for (int i = 0; i < n; ++i) {
//             A[i] = pow2[p[i]];
//             B[i] = pow2[q[i]];
//         }

//         // Precompute prefix max for A and B
//         vector<int> Amax(n), Bmax(n);
//         Amax[0] = A[0];
//         Bmax[0] = B[0];
//         for (int i = 1; i < n; ++i) {
//             Amax[i] = max(Amax[i-1], A[i]);
//             Bmax[i] = max(Bmax[i-1], B[i]);
//         }

//         // For each i, maintain two pointers to current max in A and B
//         int maxA = 0, maxB = 0;
//         vector<int> res(n);
//         for (int i = 0; i < n; ++i) {
//             int ans = 0;
// //             // For j = 0 to i, A[j] + B[i-j]
// //             // Since both are powers of two and unique, the max is at either maxA + B[i-maxA_index] or A[j] + maxB
// //             // Try all possible j = 0 to i, but since n is up to 1e5, we need O(n)
// //             // So, we can maintain the max as we go
// //             int curA = 0, curB = 0;
// //             for (int j = 0; j <= i; ++j) {
// //                 curA = max(curA, A[j]);
// //                 curB = max(curB, B[i-j]);
// //                 ans = max(ans, A[j] + B[i-j]);
// //             }
// //             res[i] = ans % MOD;
// //         }

// //         // But the above is still O(n^2). Let's do better:
// //         // For each i, the max sum is A[j_max] + B[i-j_max], where j_max is the index of max in A[0..i]
// //         // and i-j_max is the index of max in B[0..i]
// //         // So, we can for each i, try both Amax[i] + B[0] and A[0] + Bmax[i], and the max among them
// //         // But actually, for each i, the max is Amax[j] + Bmax[i-j] for j = 0 to i
// // //         // But as both arrays are permutations, the largest two numbers will always be at the ends

// // //         // Instead, use two pointers to track max in A and B as i increases
// // //         int idxA = 0, idxB = 0;
// // //         int curMaxA = A[0], curMaxB = B[0];
// // //         for (int i = 0; i < n; ++i) {
// // //             if (A[i] > curMaxA) curMaxA = A[i];
// // //             if (B[i] > curMaxB) curMaxB = B[i];
// // //             res[i] = (curMaxA + curMaxB) % MOD;
// // //         }

// // //         for (int i = 0; i < n; ++i) {
// // //             cout << res[i] << " \n"[i == n-1];
// // //         }
// // //     }
// // //     return 0;
// // // }

// // #include <iostream>
// // using namespace std;

// // string solve(long long a, long long b, long long c, long long d) {
// //     while (a > 0 && b > 0) {
// //         // Optimization: detect stable direct-attack phase
// //         if (a > 1 && b > 1 && (c <= 0 || c > a) && (d <= 0 || d > b)) {
// //             if (c <= 0 && d > 0) return "Flower";
// //             if (d <= 0 && c > 0) return "Gellyfish"; 
// //             return (b <= a) ? "Gellyfish" : "Flower";
// //         }
        
// //         // Gellyfish's turn
// //         if (c > 0) {
// //             if (b == 1) {
// //                 return "Gellyfish"; // Win immediately
// //             }
// // //             if (a == 1 && d > 0) {
// // //                 d--; // Must defend by killing Flower's knight
// // //             } else if (d == 1) {
// // //                 d--; // Kill vulnerable knight
// // //             } else {
// // //                 b--; // Attack Flower directly
// // //             }
// // //         }
        
// // //         if (b <= 0) return "Gellyfish";
        
// // //         // Flower's turn  
// // //         if (d > 0) {
// // //             if (a == 1) {
// // //                 return "Flower"; // Win immediately
// // //             }
// // //             if (b == 1 && c > 0) {
// // //                 c--; // Must defend by killing Gellyfish's knight
// // //             } else if (c == 1) {
// // //                 c--; // Kill vulnerable knight
// // //             } else {
// // //                 a--; // Attack Gellyfish directly
// // //             }
// // //         }
        
// // //         if (a <= 0) return "Flower";
        
// // //         // Check for knight eliminations
// // //         if (c <= 0 && d > 0) return "Flower";
// // //         if (d <= 0 && c > 0) return "Gellyfish";
// // //     }
    
// // //     return a > 0 ? "Gellyfish" : "Flower";
// // // }

// // // int main() {
// // //     ios_base::sync_with_stdio(false);
// // //     cin.tie(NULL);
    
// // //     int t;
// // //     cin >> t;
// // //     while (t--) {
// // //         long long a, b, c, d;
// // //         cin >> a >> b >> c >> d;
// // //         cout << solve(a, b, c, d) << "\n";
// // //     }
// // //     return 0;
// // // }


// // #include <iostream>
// // using namespace std;

// // string solve(long long a, long long b, long long c, long long d) {
// //     while (a > 0 && b > 0 && c > 0 && d > 0) {
// //         // Optimization: if both will attack directly from now on
// //         if (d > b && c > a && a > 1 && b > 1) {
// //             return (b <= a) ? "Gellyfish" : "Flower";
// //         }
        
// //         // Gellyfish's turn
// //         if (b == 1) {
// //             return "Gellyfish"; // Immediate win
// //         }
        
// //         // Attack the target with lower HP
// //         if (d <= b) {
// //             d--; // Attack Flower's knight
// //         } else {
// //             b--; // Attack Flower directly
// //         }
        
// //         if (b <= 0) return "Gellyfish";
// //         if (d <= 0) return "Gellyfish";
        
// //         // Flower's turn
// //         if (a == 1) {
// //             return "Flower"; // Immediate win
// //         }
        
// //         // Attack the target with lower HP
// //         if (c <= a) {
// //             c--; // Attack Gellyfish's knight
// //         } else {
// //             a--; // Attack Gellyfish directly
// //         }
        
// //         if (a <= 0) return "Flower";
// //         if (c <= 0) return "Flower";
// //     }
    
// //     // Handle end cases where someone lost their knight
// //     if (c <= 0 && d > 0) return "Flower";
// //     if (d <= 0 && c > 0) return "Gellyfish";
// //     if (a <= 0) return "Flower";
// //     if (b <= 0) return "Gellyfish";
    
// //     return "Draw";
// // }

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
    
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         long long a, b, c, d;
// //         cin >> a >> b >> c >> d;
// //         cout << solve(a, b, c, d) << "\n";
// //     }
// //     return 0;
// // }
// #include <iostream>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n, q;
//         cin >> n >> q;

//         vector<int> b(n + 1);
//         for (int i = 1; i <= n; i++) {
//             cin >> b[i];
//         }

//         vector<pair<int, int> > modifications(q);
//         for (int i = 0; i < q; i++) {
//             int x, y, z;
//             cin >> x >> y >> z;
//             modifications[i] = make_pair(x, y); // Fixed assignment
//         }

//         bool possible = true;

//         // Check constraints in reverse
//         for (int i = q - 1; i >= 0; i--) {
//             int x = modifications[i].first;
//             int y = modifications[i].second;
//             if (b[x] > b[y]) {
//                 possible = false;
//                 break;
//             }
//         }

//         if (!possible) {
//             cout << -1 << '\n';
//         } else {
//             for (int i = 1; i <= n; i++) {
//                 cout << b[i];
//                 if (i < n) cout << " ";
//             }
//             cout << '\n';
//         }
//     }

//     return 0;
// }



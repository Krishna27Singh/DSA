#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

// int maxSubarraySum(const vector<int>& a, int &startIdx, int &endIdx) {
//     if (a.empty()) {
//         startIdx = endIdx = -1;
//         return 0;
//     }

//     int currentSum = a[0];
//     int maxSum = a[0];

//     int tempStart = 0;   
//     startIdx = 0;
//     endIdx = 0;

//     for (int i = 1; i < a.size(); i++) {
//         if (a[i] > currentSum + a[i]) {
//             currentSum = a[i];
//             tempStart = i;   
//         } else {
//             currentSum += a[i];
//         }

//         if (currentSum > maxSum) {
//             maxSum = currentSum;
//             startIdx = tempStart;
//             endIdx = i;
//         }
//     }

//     return maxSum;
// }

// int maxSubarraySum2(const vector<int>& a, const vector<int>& b) {
//     int n = a.size();
//     if (n == 0) return 0;

//     int noChange = a[0];
//     int usedChange = a[0] + b[0];   

//     int ans = max(noChange, usedChange);

//     for (int i = 1; i < n; i++) {
//         usedChange = max(
//             noChange + a[i] + b[i],   
//             usedChange + a[i]         
//         );

//         noChange = max(
//             a[i],
//             noChange + a[i]
//         );

//         ans = max({ans, noChange, usedChange});
//     }

//     return ans;
// }



void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    k &= 1;

    vector<long long> L(n); 
    for(int i = 0;i < n;i++){
        L[i] = (i && L[i-1]>0 ? L[i-1] : 0ll) + a[i]; 
    }   

    vector<long long> R(n); 
    for(int i = n-1;i >= 0;i--){
        R[i] = (i+1<n && R[i+1]>0 ? R[i+1] : 0ll) + a[i];
    }

    if(k == 0){
        long long ans = *max_element(L.begin(),L.end());
        cout << ans << "\n";
    }
    else{
        long long ans = LONG_MIN;
        for(int i = 0;i < n;i++){
            ans = max(ans,L[i]+R[i]-a[i]+b[i]);
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

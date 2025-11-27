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
// #include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1e9;

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n, MAX_A);
        vector<tuple<int,int,int>> c1_constraints, c2_constraints;
        for(int i=0; i<q; ++i) {
            int c, l, r;
            cin >> c >> l >> r;
            if(c==1) c1_constraints.push_back({l-1, r-1, k});
            else c2_constraints.push_back({l-1, r-1, k});
        }

        // Process c==2 constraints first (MEX)
        for(auto [l, r, k]: c2_constraints) {
            vector<int> used(r-l+1, 0); // Which indices have been assigned
            int idx = l;
            // Assign 0,...,k-1
            for(int val=0; val<k && idx<=r; ++val, ++idx)
                a[idx] = val;
            // For others in window, avoid k
            for(int i=idx; i<=r; ++i)
                if(a[i] == k) a[i] = MAX_A;
        }
        
        // Process c==1 constraints (min)
        for(auto [l, r, k]: c1_constraints) {
            // Set at least one a[j] = k in [l, r]
            bool found=false;
            for(int i=l;i<=r;++i){ if(a[i]==k){ found=true; break; } }
            if(!found) a[l]=k;
            // All others can be >= k (already MAX_A so OK)
        }
        
        // Print
        for(int i=0; i<n; ++i) cout << a[i] << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

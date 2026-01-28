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

int kadane(int l, int r, vector<int> &a){
    int maxSoFar = a[l];
    int currMax = a[l];

    for(int i = l+1; i<=r; i++){
        currMax = max(a[i], currMax + a[i]);
        maxSoFar = max(maxSoFar, currMax); 
    }

    return maxSoFar;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<pair<int, int>> segments;
    vector<int> parity;
    for(int i = 0; i<n-1; i++){
        parity.push_back(a[i+1] - a[i]);
    }
    // for(auto i: parity){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int ans = INT_MIN;
    int start, end;
    //check for continuous odd segments
    for(int i = 0; i<n-1; i++){
        if(parity[i]%2 != 0){
            start = i;
            end = i;
            while(end+1 < n-1 && parity[end+1]%2 != 0){
                end++;
            }
            end++;
            auto mypair = make_pair(start, end);
            segments.push_back(mypair);
            i = end;
        }
    }
    // for(auto i: segments){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    for(auto seg: segments){
        int l = seg.first;
        int r = seg.second;

        int maxSum = kadane(l, r, a);
        ans = max(ans, maxSum);
    }

    sort(a.begin(), a.end());
    ans = max(ans, a[n-1]);

    // Output
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

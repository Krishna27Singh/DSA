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

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int totalSum = 0;
    for(int i = 0; i<n-1; i++){
        totalSum += abs(a[i+1]-a[i]);
    }
    int originalTotalSum = totalSum;
    // cout<<totalSum<<endl;
    totalSum = min(totalSum, originalTotalSum - abs(a[1]-a[0]));
    // cout<<totalSum<<endl;
    totalSum = min(totalSum, originalTotalSum - abs(a[n-1]-a[n-2]));
    // cout<<totalSum<<endl;
    for(int i = 0; i<n-2; i++){
        int withoutRemove = abs(a[i+1]-a[i]) + abs(a[i+2]-a[i+1]);
        int withRemove = abs(a[i+2]-a[i]);
        if(withRemove < withoutRemove){
            totalSum = min(originalTotalSum - (withoutRemove - withRemove), totalSum);
        }
    }
    cout<<totalSum<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

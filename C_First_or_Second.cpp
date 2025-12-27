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

void solve() {
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >>a[i];
        
    vector<long long> suffix(n+1, 0);
    for(int i=n - 1; i>=0; i--) {
        suffix[i] = suffix[i + 1]+ a[i];
    }

    long long ans = -suffix[1];

    long long prefix = a[0];
    for (int rem = 1; rem<n; rem++) {
        long long currentAns = prefix - suffix[rem + 1];
        ans = max(ans, currentAns);
        prefix += abs(a[rem]);
    }

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

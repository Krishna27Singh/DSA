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
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

bool canFortify(long long targetBases, long long n, long long m, long long k) {
    long long S = targetBases - 1; 
    
    if (S < 0) return true; 
    if (S == 0) return 0 <= m; 
    long long spaceL = k - 1;
    long long spaceR = n - k;

    long long minL = max(0LL, S - spaceR);
    long long maxL = min(S, spaceL);

    if (minL > maxL) return false;

    long long bestL;
    long long midTarget = S / 2;
    
    if (midTarget < minL) bestL = minL;
    else if (midTarget > maxL) bestL = maxL;
    else bestL = midTarget;
    
    long long bestR = S - bestL;
    long long X = max(bestL, bestR);
    long long Y = min(bestL, bestR);
    
    long long cost = 2 * X + Y - 1;
    
    return cost <= m;
}

void solve() {
    long long n, m, k; cin>>n>>m>>k;

    long long low = 1, high = n;
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canFortify(mid, n, m, k)) {
            ans = mid;
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
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

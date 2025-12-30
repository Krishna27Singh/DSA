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

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];
    vector<int> c(n);
    for(int i = 0; i<n; i++) cin>>c[i];

    vector<bool> validB(n, true);
    for(int j=0;j<n; j++) {
        for(int m=0; m<n; m++) {
            if(a[m] >= b[(m + j)%n]) {
                validB[j] = false;
                break;
            }
        }
    }

    vector<bool> validBC(n, true);
    for(int s=0; s<n; s++) {
        for(int x=0; x<n; x++) {
            if(b[x] >= c[(x + s)%n]) {
                validBC[s] = false;
                break;
            }
        }
    }

    ll validAns = 0;
    int cntValidBC = 0;
    for(int s=0; s<n; s++) {
        if(validBC[s]) cntValidBC++;
    }

    for(int j=0; j<n; j++) {
        if(validB[j]) validAns += cntValidBC;
    }

    ll ans = 1LL*validAns*n;
    cout<<ans<<endl;

    // Output

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

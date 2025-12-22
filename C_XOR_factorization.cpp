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

void solve()
{
    ll n,k;
    cin >> n >> k;
    ll tight = k;
    if(k & 1) {
        for(int i = 0; i<k; i++) {
            cout << n << ' ';
        }
        cout << endl;
        return;
    }
 
    int ans[k]{};
    int idx = 31 - __builtin_clz(n);
 
    for(int i = idx; i >= 0; i--) {
        if((n >> i) & 1) {
            ll leave;
            if(tight > 0) {
                leave = tight - 1;
                tight--;
            }
            else{
                leave = 0;
            }
            for(int j = 0; j < k; j++) {
                if(j == leave) continue;
                ans[j] |= (1<<i);
            }
        }
        else{
            ll rem = k - tight;
            ll up = rem - rem % 2;
            for(int j = k-1; up; j--, up--) {
                ans[j] |= (1<<i);
            }
        }
    }
 
    for(int i = 0; i < k; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

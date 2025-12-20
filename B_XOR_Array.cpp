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

int flipBits(int x) {
    int mask = 0;
    int temp = x;
    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }
    return x ^ mask;
}


void solve(){
    int n, l, r; cin>>n>>l>>r;
    vector<int> a(n, 0);

    vector<int> prefixXOR(n+1, 0);
    for(int i = 1;i <= n;i++){
        prefixXOR[i] = i;
    }

    prefixXOR[r] = prefixXOR[l-1];

    for(int i = 1; i<=n; i++){
        a[i-1] = prefixXOR[i] ^ prefixXOR[i-1];
    }

    for(auto i: a){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

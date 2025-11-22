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
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i = 1; i<=n; i++) cin>>b[i];

    int net = 0;
    int lastImp = 0;
    for (int i = 1; i <= n; ++i) {
        int d = a[i] ^ b[i];
        net ^= d;
        if(d) lastImp = i;
    }

    if (net == 0) {
        cout<<"Tie"<<endl;
    } else {
        if (lastImp %2 == 1) cout<< "Ajisai"<<endl;
        else cout << "Mai"<<endl;
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

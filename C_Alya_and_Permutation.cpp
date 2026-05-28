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
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************
k = 0
and or and or and or ...
*/

/*
****************************************** Testing ****************************************************

*/

int complement(int n) {
    int mask = 0;

    int temp = n;
    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return (~n) & mask;
}

void solve(){
    int n; cin>>n;

    int lsb = n & (-n);

    int bits = 32 - __builtin_clz(n);

    int comp = complement(n);

    if (n % 2 == 0) {
        int H = 1 << (bits - 1); 
        
        int k = (1 << bits) - 1; 
        cout << k << "\n";

        int e5 = H;
        int e4 = H - 1;
        int e3 = H - 2;
        int e2 = 1;
        int e1 = (n == 6) ? 5 : 3; 

        for (int i = 1; i <= n; i++) {
            if (i == e1 || i == e2 || i == e3 || i == e4 || i == e5) continue;
            cout << i << " ";
        }

        cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";
    }
    else{
        cout<<n<<endl;
        // cout<<"lsb: "<<lsb<<"n - lsb: "<<n-lsb<<endl;
        for(int i = 1; i<=n-1; i++){
            if(i == lsb || i == (n - lsb)) continue;
            cout<<i<<" ";
        }
        cout<<lsb<<" "<<(n - lsb)<<" "<<n<<endl;
    }

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

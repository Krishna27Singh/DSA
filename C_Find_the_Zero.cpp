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
0 0 -> 1
0 num 
num 0
num num 

ak = 0 (1 indexed)
n+1 max queries 

1 2 3 0 0 0 
0 1 0 2 0 3
0 0 0 1 2 3
1 0 2 0 3 0 
1 2 0 0 
0 0 1 2
0 1 0 2
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    
    cout<<"? "<<1<<" "<<2<<endl;
    cout.flush();
    int x; cin>>x;
    if(x == 1){
        cout<<"! "<<1<<endl;
        return;
    }
    cout<<"? "<<2<<" "<<3<<endl;
    cout.flush();
    cin>>x;
    if(x == 1){
        cout<<"! "<<2<<endl;
        return;
    }
    cout<<"? "<<1<<" "<<3<<endl;
    cout.flush();
    cin>>x;
    if(x == 1){
        cout<<"! "<<1<<endl;
        return;
    }

    for (int i = 4; i < 2 * n; i += 2) {
        cout<<"? "<<i<<" "<<i+1<<endl;
        cout.flush();
        cin>>x;
        if(x==1){
            cout<<"! "<<i<<endl;
            return;
        }
    }

    cout<<"! "<<2*n<<endl;

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

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
for each possible value of mex calcualte
extras + 
*/

/*
****************************************** Testing ****************************************************
6
1 2 0 1 3 2
1 3 5 4 3 2 1

0 1 2 3 
1 2 2 1

0 1 2 3 4 5 6
1 0 0 0 0 0 0
0 1 1 1 1 1 1
0 

*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> mpp(n+1, 0);
    for(auto i: a) mpp[i]++;
    vector<int> l(n+1, 0);
    for(int i = 0; i<=n; i++) l[i] = mpp[i];
    int mex = 0;
    for(int i = 0; i<=n; i++){
        if(mpp[i] == 0){
            mex = i;
            break;
        }
    }
    
    int eo = 0;
    for(int i = 0; i<=n; i++){
        if(mpp[i] > 0){
            eo += mpp[i] - 1;
            mpp[i] = 1;
        }
    }

    vector<int> suff(n+2, 0);
    for(int i = n; i>=0; i--){
        suff[i] = suff[i+1] + mpp[i];
    }

    vector<int> ans(n+2, 0); 
    // ans[0] = 1;

    for(int k = 0; k<=mex; k++){
        int left = l[k];
        if(left == 0) left = 1;
        int right = eo + suff[k];

        if(left <= right){
            ans[left] += 1;
            ans[right + 1] -= 1;
        }
    }

    for(int i = 1; i <= n; i++){
        ans[i] += ans[i-1];
    }
    ans[0] = 1;

    for(int i = 0; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
    
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

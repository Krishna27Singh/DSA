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
s1, s2, s3, .. sn -> find a sequence in the same order
for any two adjacent (i(j+1) % i(j) == 0) && (si(j+1) > si(j))
(si(j+1) > si(j)) -> the sequence should be sorted !


*/

/*
****************************************** Testing ****************************************************
1 4 2 3 6 4 9


*/


void solve(){
    int n; cin>>n;
    vector<int> s(n);
    for(int i = 0; i<n; i++) cin>>s[i];

    vector<int> dp(n+1, 1);

    for(int i = 1; i<=n; i++){
        int curr = s[i-1];
        for(int j = 2*i; j<=n; j+=i){
            int next = s[j-1];
            if(next > curr){
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }

    int ans = INT_MIN;

    for(auto i: dp) ans = max(ans, i);

    cout<<ans<<endl;

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

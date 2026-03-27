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
m * l <= 1e5
danger = max(di)
minimum value x such that the 
danger <= x no matter what

m -> animatronics
l -> total seconds
n -> time at which flashlight can bi shined 
d -> danger level of ith animatronics
initial d1 = d2 .. = dm = 0
di += 1 every second for exactly one animatronics

upper bound of answer -> l
lower bound ? -> BS

we want n+1 monsters 
*/

/*
****************************************** Testing ****************************************************
2 2 7
6 7


*/

bool check(long long x, int n, int m, long long l, const vector<long long>& a) {
    vector<long long> A(m, 0);
    long long prev_time = 0;

    for (int i = 0; i <= n; ++i) {
        long long curr_time = (i == n) ? l : a[i];
        long long d = curr_time - prev_time;
        prev_time = curr_time;

        int k = min(m, n - i + 1);          
        
        sort(A.begin(), A.end());

        vector<long long> V(A.end() - k, A.end());

        for (int j = 1; j < k; ++j) {
            long long diff = V[j] - V[j-1];
            if (diff == 0) continue;
            
            long long cost = diff * j; 
            
            if (d >= cost) {
                d -= cost;
                for (int p = 0; p < j; ++p) V[p] = V[j];
            } else {
                long long add = d / j;
                long long rem = d % j;
                for (int p = 0; p < j; ++p) {
                    V[p] += add + (p >= j - rem ? 1 : 0);
                }
                d = 0;
                break;
            }
        }

        if (d > 0) {
            long long add = d / k;
            long long rem = d % k;
            for (int p = 0; p < k; ++p) {
                V[p] += add + (p >= k - rem ? 1 : 0);
            }
        }

        for (int j = 0; j < k; ++j) {
            A[m - k + j] = V[j];
        }


        if (i < n) {
            A[m - 1] = 0;
        }
    }
    
    return A[m-1] <= x;
}

void solve(){
    int n, m, l; cin>>n>>m>>l;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    if(m == 1){
        cout<<l - a[n-1]<<endl;
        return;
    }

    int lo = 0; 
    int hi = l;
    int ans = l;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        
        if(check(mid, n, m, l, a)){
            ans = mid;      
            hi = mid - 1;  
        }
        else{
            lo = mid + 1;  
        }
    }

    cout << ans <<endl;
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

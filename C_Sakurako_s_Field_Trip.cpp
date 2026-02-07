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
disturbance = number of aj = aj+1
minimize the number of disturbances

can swap i and n-i-1

if(idx >= n-1) no need to check furthur

*/

// int f(int idx, vector<int> &a){
//     if(idx >= a.size()/2) return 0;
    
//     int ans = INF;

//     int case1 = (a[idx] == a[idx+1]) + f(idx+1, a);

//     int case2 = INF;
//     if(idx != a.size()-idx-1){
//         swap(a[idx], a[a.size() - idx - 1]);
//         case2 = min(case2, (a[idx] == a[idx+1]) + f(idx+1, a));
//         swap(a[idx], a[a.size() - idx - 1]);
//     }

//     int case3 = INF;
//     if((idx+1) != a.size()-(idx+1)-1){
//         swap(a[idx+1], a[a.size() - (idx+1) - 1]);
//         case3 = min(case3, (a[idx] == a[idx+1]) + f(idx+1, a));
//         swap(a[idx+1], a[a.size() - (idx+1) - 1]);
//     }

//     return min(case1, min(case2, case3));
// }

void solve(){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=n/2-1;i>=1;i--){
            if(a[i]==a[i+1] || a[n-i+1]==a[n-i]){
                swap(a[i],a[n-i+1]);
            }
        }
        int re=0;
        for(int i=1;i<n;i++){
            re+=(a[i]==a[i+1]);
        }
        cout<<re<<endl;

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

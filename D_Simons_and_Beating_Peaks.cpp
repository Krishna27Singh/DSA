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

array a should have no element ai such that ai = max({ai-1, ai, ai+1})
operations we can perform :
1) remove ai-1
2) remove ai+1
minimum operations such that the array becomes beautiful?

can this be solved using dp?

make use of the fact that the array is permuatation initially ***

maintain two pointers i and j such that i <= j in the array a, initially i = 0 and j = n-1
in the array ai, ai+1, ai+2.... aj -> lets call this array a*
maxi1 -> maximum element in the array a*
maxi2 -> seecond maximum element in the array a*
maxi1 and maxi2 should not be terminal elements in the array a*

we have to remove all the elements in between maxi1 and maxi 2 and 
we have to remove all the elements from maxi1 to that end of the array where maxi2 is not present

*/


void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = 0;

    int maxi1 = INT_MIN, maxi2 = INT_MIN;
    int maxi1Idx = -1, maxi2Idx = -1;
    for(int i = 0; i<n; i++){
        if(a[i] > maxi1){
            maxi2 = maxi1;
            maxi2Idx = maxi1Idx;
            maxi1 = a[i];
            maxi1Idx = i;
        }
        else if(a[i] > maxi2){
            maxi2 = a[i];
            maxi2Idx = i;
        }
    }

    if(maxi2 < maxi1){
        ans += (n-1)-maxi1Idx;
        ans += (maxi1Idx-maxi2Idx-1);
        while(true){
            int i = maxi2Idx;
            // we need to search for the maximum element till i (not including i)
            int maxTillI = INT_MIN;
            int maxTillIIdx = -1;
            for(int j = 0; j<i; j++){
                if(a[j] > maxTillI){
                    maxTillI = a[j];
                    maxTillIIdx = j;
                }
            }
            if(maxTillI == i - 1){
                maxi2Idx = maxTillIIdx;
            }
            else if(maxTillI == 0){
                cout<<ans<<endl;
                return;
            }
            else{
                ans += i - maxTillI - 1;
                maxi2Idx = maxTillIIdx;
            }
        }
    }
    else{
        ans += maxi1Idx;
        ans += (maxi2Idx-maxi1Idx-1);
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

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
const ll MOD = 676767677;

/*
****************************************** APPROACH **************************************************
f(a) -> number of ways to partition a such that each subarray has the same sum .

a length is x+y
a contains x 1s and y -1s

minimum value of f(a) for all possible a's?
ans what is that array a?

how much extra amount do i have after neutralization of equivalent 1 and -1 pairs ?
x = 2
y = 6

1 -1 1 -1 -1 -1 -1 -1

1 -1 -1 1 -1 -1 -1 -1

1 -1 -1 -1 -1 -1 1 -1

if y > x the sum can be either -1 or -2 or -3 and so on ... but it can't be 0 because we can't neutralize all the -1s with 1s
if x > y the sum can be either 1 or 2 or 3 and so on ... but it can't be 0 because we can't neutralize all the 1s with 

and the order does not matter the number of ways to partition the array is the same for all arrays with the same x and y
so we can just calculate the number of ways to partition an array with x 1s and y -1s and the answer will be the same for all arrays with the same x and y

to calculate put the neutralising factor in the starting

1 -1 1 -1 and so on and then after that put the one which is in excess 

1 -1 1 -> 1 way 
1 -1 1 1 -> 2 ways
1 -1 1 1 1 -> 2 ways
1 -1 1 1 1 1 -> 3 ways
1 -1 1 1 1 1 1 -> 3 ways
1 -1 1 1 1 1 1 1 -> 4 ways 

1 1 1 1 1 -1 -1 -1 -1
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int x, y; cin>>x>>y;

    int neutral = min(x, y);
    int excess = abs(x-y);

    if(x == y){
        cout<<1<<endl;
        for(int i = 0; i<x; i++) cout<<1<<" ";
        for(int i = 0; i<y; i++) cout<<-1<<" ";
        cout<<endl;
        return;
    }

    int ans =0;

    for(int i = 1; i*i <= excess; i++){
        if(excess % i == 0){
            ans++;
            if(excess/ i != i) ans++;
        }
    }
    cout<<ans<<endl;
    for(int i = 0; i<x; i++) cout<<1<<" ";
    for(int i = 0; i<y; i++) cout<<-1<<" ";
    cout<<endl;

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

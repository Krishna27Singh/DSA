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
ai = ai + (ai % 10)
ai = ai + last digit of ai
need to make all values equal 
yes no ?

ending at 1
pattern ?
1 2 4 8 6 
  2 4 8 6 



false -> 3 5 7 9 

ending at 3
3 6 2 4 8 
  6 2 4 8

false -> 1 5 7 9

ending at 5
5 0 0 0 ...
if something is ending by 5 i can only add 5 to it 

ending at 7
7 4 8 6 2 
  4 8 6 2

false -> 1 3 5 9 

ending at 9
9 8 6 2 4 
  8 6 2 4

false -> 1 3 5 7
*/

/*
****************************************** Testing ****************************************************
10
2
6 11
3
2 18 22
5
5 10 5 10 5
4
1 2 4 8
2
4 5
3
93 96 102
2
40 6
2
50 30
2
22 44
2
1 5


Yes
No
Yes
Yes
No
Yes
No
No
Yes
No

*/

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    bool has5 = false;
    for(auto x : a){
        if(x % 5 == 0) has5 = true;
    }

    if(has5){
        for(auto &x : a){
            if(x % 10 == 5) x += 5;
        }
        for(int i = 1; i < n; i++){
            if(a[i] != a[0]){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }

    for(auto &x : a){
        while(x % 10 != 2){
            x += x % 10;
        }
    }

    int rem = a[0] % 20;
    for(auto x : a){
        if(x % 20 != rem){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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

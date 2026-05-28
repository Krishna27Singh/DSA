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
18 + 21 + 25 -> 64 
n    n    n

60 unit plank. how many planks needed? 

18 + 21 -> 39, 25, rem = 60 - 39 = 21
18 + 25 -> 43, 21, rem = 60 - 43 = 17
21 + 25 -> 46, 18, rem = 60 - 46 = 14
18 + 18 -> 36, 25, rem = 60 - 36 = 24
21 + 21 -> 42, 18, rem = 60 - 42 = 18
25 + 25 -> 50, 18, rem = 60 - 50 = 10


18 + 18 + 21
21 + 21 + 18
18 + 18 + 18 
25 + 25 

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;

    int ans = ceil(n / 2.0) + ceil((2.0 * n) / 3);
    int num = ceil((2.0 * n) / 3);

    if(n%2){
        if(num%2 == 0){
            int total18 = (num*3)/2;
            int total21 = (num*3)/2;
            if(total18 - 1 >= n && total21 - 1 >= n) ans--;
        }
        else{
            int total18 = (num*3)/2;
            int total21 = (num*3)/2 + 1;
            if(total18 - 1 >= n && total21 - 1 >= n) ans--;
            else{
                total18 = (num*3)/2 + 1;
                total21 = (num*3)/2;
                if(total18 - 1 >= n && total21 - 1 >= n) ans--;
            }
        }
    }

    cout<< ans<<endl;
    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

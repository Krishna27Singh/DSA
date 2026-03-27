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
0, 1, ... n-1, n

unfairness -> sum of differences of neighbours

difference -> number of set bit in xor of x and y 

1	00001	11	01011	21	10101
2	00010	12	01100	22	10110
3	00011	13	01101	23	10111
4	00100	14	01110	24	11000
5	00101	15	01111	25	11001
6	00110	16	10000	26	11010
7	00111	17	10001	27	11011
8	01000	18	10010	28	11100
9	01001	19	10011	29	11101
10	01010	20	10100	30	11110
                        31  11111
                        32  10000

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll n; cin>>n;

    ll ans = 0;

    while(n>0){
        ans += n;
        n /= 2;
    }

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

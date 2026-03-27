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
move -> 101 -> 111
        111 -> 101
minimum and maximum number of ones in string?
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    vector<int> segs;

    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            if(i-1>=0 && i+1<n && s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
        }
    }

    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            int len = 0;
            while(s[i] == '1'){
                len++;
                i++;
            }
            i--;
            segs.pb(len);
        }
    }

    int mini = 0;
    int maxi = 0;
    for(auto seg : segs){
        maxi += seg;
        mini += seg/2 + 1;
    }

    cout<<mini<<" "<<maxi<<endl;

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

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
r g b
2 7 3
GBGBGBGRGRG

/*
****************************************** Testing ****************************************************

*/

void solve(){
    // int r, g, b; cin>>r>>g>>b;
    int clrs[3];
    cin>>clrs[0]>>clrs[1]>>clrs[2];
    char chars[3] = {'R', 'G', 'B'};
    
    string s = "";
    while(true){
        int l = s.size();
        int bi = -1;
        int maxi = -1;

        for(int i = 0; i<3; i++){
            if (clrs[i] == 0) continue;
            if (l >= 1 && chars[i] == s[l-1]) continue;
            if (l >= 3 && chars[i] == s[l-3]) continue;
            bool flag = (l >= 2 && chars[i] == s[l-2]);
            
            if (clrs[i] > maxi) {
                maxi = clrs[i]; bi = i;
            } 
            else if (clrs[i] == maxi) {
                if (flag) bi = i;
            }
        }
        if (bi == -1) break;
        s += chars[bi];
        clrs[bi]--;
    }

    cout<<s<<endl;

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

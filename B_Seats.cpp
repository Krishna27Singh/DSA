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

*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    int ans = 0;
    for(auto i: s) if(i == '1') ans++;
    if(ans == 0 && (n==1 || n==2 || n==3)){
        cout<<1<<endl;
        return;
    }
    if(ans == 0){
        ans++;
        s[n-2] = '1';
    }
    vector<int> validGaps;
    int currentGap = 0;
    int beginGap = 0;
    int startIdx;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') beginGap++;
        else{
            startIdx = i;
            break;
        }
    }
    if(beginGap > 0){
        if(beginGap == 2) ans++;
        else if(beginGap >= 3){
            ans++;
            validGaps.pb(beginGap-2);
        }
    }
    for(int i = startIdx; i<n; i++){
        if(s[i] == '0') currentGap++;
        else{
            if(currentGap > 0) validGaps.pb(currentGap);
            currentGap = 0;
        }
    }
    int endGap = 0;
    for(int i = n-1; i>=0; i--){
        if(s[i] == '0') endGap++;
        else break;
    }
    
    if(endGap > 0){
        if(endGap == 2) ans++;
        else if(endGap >= 3){
            ans++;
            validGaps.pb(endGap-2);
        }
    }

    // for(auto i: validGaps) cout<<i<<" ";
    // cout<<endl;

    for(auto gap : validGaps){
        ans += gap/3;
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

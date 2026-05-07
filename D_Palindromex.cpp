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
2 cases possible
1 0 present in our sequence
2 0 present in our sequence
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    vector<int> a(2*n);
    for(int i = 0; i<2*n; i++) cin>>a[i];

    vector<int> mex1;
    vector<int> mex2;
    vector<int> mex3;

    int pos1 = -1, pos2;
    for(int i = 0; i<2*n; i++){
        if(a[i] == 0 && pos1 == -1) pos1 = i;
        else if(a[i] == 0 && pos1 != -1) pos2 = i;
    }
    int opos1 = pos1, opos2 = pos2;
    // cout<<"pos1: "<<pos1<<" pos2: "<<pos2<<endl;

    bool possibleCase1 = true;
    while(pos1 <= pos2){
        if(a[pos1] != a[pos2]){
            possibleCase1 = false;
            break;
        }
        else{
            mex1.pb(a[pos1]);
            // cout<<"exe: "<<a[pos1]<<" "<<a[pos2]<<endl;
            pos1++;
            pos2--;
        }
    }
    pos1 = opos1-1, pos2 = opos2+1;

    while(pos1 >=0 && pos2 < 2*n){
        if(a[pos1] != a[pos2]) break;
        else{
            mex1.pb(a[pos1]);
            pos1--;
            pos2++;
        }
    }

    pos1 = opos1, pos2 = opos2;

    int l = pos1, r = pos1;
    while(l>=0 && r<2*n){
        if(a[l] != a[r]) break;
        else{
            mex2.pb(a[l]);
            l--;
            r++;
        }
    }

    l = pos2, r = pos2;
    while(l>=0 && r<2*n){
        if(a[l] != a[r]) break;
        else{
            mex3.pb(a[l]);
            l--;
            r++;
        }
    }

    // for(auto i: mex1) cout<<i<<" "; 
    // cout<<endl;
    // for(auto i: mex2) cout<<i<<" ";
    // cout<<endl;
    // for(auto i: mex3) cout<<i<<" ";
    // cout<<endl;

    sort(all(mex1));
    sort(all(mex2));
    sort(all(mex3));

    int ans = 1;
    int mex = 0;
    for(int i = 0; i<sz(mex2); i++){
        if(mex2[i] == mex) mex++;
        else break;
    }
    ans = max(ans, mex);
    mex = 0;
    for(int i = 0; i<sz(mex3); i++){
        if(mex3[i] == mex) mex++;
        else break;
    }
    ans = max(ans, mex);

    if(possibleCase1){
        mex = 0;
        for(int i = 0; i<sz(mex1); i++){
            if(mex1[i] == mex) mex++;
            else break;
        }
        ans = max(ans, mex);
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

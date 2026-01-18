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

    string sortedS = s;
    sort(sortedS.begin(), sortedS.end());

    if(sortedS[0]==sortedS[n-1] || is_sorted(s.begin(), s.end())){
        cout<<"Bob"<<endl;
        return;
    }
    
    int replace0s = 0;
    int idx = n-1;
    while(sortedS[idx]=='1'){
        if(sortedS[idx] != s[idx]) replace0s++;
        idx--;
    }

    int sufficient1s = 0;
    for(int i = 0; i<=idx; i++){
        if(s[i]=='1') sufficient1s++;
    }

    if(sufficient1s >= replace0s){
        vector<int> ans;
        vector<int> idx1s;
        vector<int> idx0s;
        for(int i = 0; i<n; i++) if(s[i]=='1') idx1s.push_back(i);
        for(int i = 0; i<n; i++) if(s[i]=='0') idx0s.push_back(i);
        reverse(idx0s.begin(), idx0s.end());

        for(int i = 0; i<replace0s; i++){
            ans.push_back(idx1s[i]);
            ans.push_back(idx0s[i]);
        }

        sort(ans.begin(), ans.end());
        cout<<"Alice"<<endl;
        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i+1<<" ";
        cout<<endl;
        return;
    }

    cout<<"Bob"<<endl;

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


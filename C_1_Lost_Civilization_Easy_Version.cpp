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
#include<stack>
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
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    // int ans = 0;
    // for(int i = 0; i<n; i++){
    //     if((i+1 < n) && (a[i] + 1 == a[i+1])){
    //         ans++;
    //         int left = a[i];
    //         while(i+1 < n && (a[i+1] > left && a[i+1]<=a[i]+1)){
    //             i++;
    //         }
    //     }
    //     else ans++;
    // }

    // cout<<ans<<endl;

    stack<int> st;
    vector<int> sufPref(n);
    for(int i = n-1; i>=0; i--){
        while((!st.empty()) && st.top() == a[i] + 1) st.pop();
        st.push(a[i]);
        sufPref[i] = st.size();
    }

    while(!st.empty()) st.pop();

    
    int ans = 0;
    for(auto i: sufPref) ans += i;
    cout<<ans<<endl;


    // cout<<st.size()<<endl;

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

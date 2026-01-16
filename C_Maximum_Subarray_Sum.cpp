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
    #impossible case
    a1, a2, 0, a4...

*/

void solve(){
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    ll maxSum = 0;
    ll currSum = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='1'){
            currSum = max(currSum + a[i], a[i]);
            maxSum = max(maxSum, currSum);
        }
        else currSum = 0;
    }

    if(maxSum > k){
        cout<<"NO"<<endl;
        return;
    }
    if(maxSum == k){
        cout<<"YES"<<endl;
        for(int i = 0; i<n; i++){
            if(s[i]=='1') cout<<a[i]<<" ";
            else cout<<-1e18<<" ";
        }
        cout<<endl;
        return;
    }

    int zer = -1;
    for(int i = 0; i<n; i++){
        if(s[i]=='0'){
            zer = i;
            break;
        }
    }

    if(zer == -1){
        cout<<"NO"<<endl;
    }
    else{
        ll prefMax = 0;
        ll prefSum = 0;
        ll sufMax = 0;
        ll sufSum = 0;
        for(int i = zer-1; i>=0; i--){
            if(s[i] == '0') break;
            prefSum += a[i];
            prefMax = max(prefMax, prefSum);
        }
        for(int i = zer + 1; i<n; i++){
            if(s[i]=='0') break;
            else{
                sufSum += a[i];
                sufMax = max(sufMax, sufSum);
            }
        }
        a[zer] = k - prefMax - sufMax;
        for(int i = 0; i<n; i++){
            if(i!=zer && s[i]=='0') a[i] = -1e18;
        }

        cout<<"YES"<<endl;
        for(auto i: a) cout<<i<<" ";
        cout<<endl;
    }

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

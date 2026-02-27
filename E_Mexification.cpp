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
set ai to the mex of all the array except ai
for all the elements

repeat this procedure k times

sum of elements in the array after these k operations

O(N*K) not possible
K <= 1e9


*/

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    unordered_map<ll, ll> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }

    set<ll> s(a.begin(), a.end());
    ll mex = 0;
    for(auto i: s){
        if(i == mex) mex++;
        else break;
    }

    sort(all(a));

    if(mex == n){
        ll ans = (mex*(mex-1))/2;
        cout<< ans<<endl;
        return;
    }

    ll newMex = -1;
    for(auto i: s){
        if(mpp[i] >= 2){
            newMex = i;
            break;
        }
    }
    if(newMex == -1){
        if(mex == n-1){
            cout<<(mex*(mex+1))/2<<endl;
        }
        else{
            if(k%2) cout<< (mex*(mex-1))/2 + ((n-1)-mex+1)*(mex)<<endl;
            else cout<< (mex*(mex-1))/2 + ((n-1)-mex+1)*(mex+1)<<endl;
        }
        return;
    }
    if(newMex > mex){
        if(k%2) cout<< (mex*(mex-1))/2 + ((n-1)-mex+1)*(mex)<<endl;
        else cout<< (mex*(mex-1))/2 + ((n-1)-mex+1)*(mex+1)<<endl;
        return;
    }


    if(k == 1){
        ll ans = 0;
        for(int i = 0; i<n; i++){
            if(a[i] > mex){
                ans += mex;
                continue;
            }

            if(mpp[a[i]] >= 2){
                ans += mpp[a[i]]*mex;
                i += mpp[a[i]]-1;
                continue;
            }

            ans += a[i];
        }

        cout<<ans<<endl;
        return;
    }

    int ans = 0;
    ans += (newMex*(newMex-1))/2;
    if(k%2) ans += ((n-1)-newMex+1)*(newMex+1);
    else ans += ((n-1)-newMex+1)*(newMex);

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

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
i, i+k, i+2k, i+3k, ... i+mk


*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    vector<bool> flag(n+1, true);
    for(int i = 0; i<n-k; i++){
        if(a[i] != a[i+k]) flag[i%k] = false;
    }
    vector<ll> ans(n+1, 0);
    // iterating mods 
    for(int i = 0; i<k; i++){
        if(flag[i]){
            ll val = -1;
            for(int j = i; j<n; j+=k){
                if(b[j] != -1){
                    val = b[j];
                    break;
                }
            }
            if(val != -1){
                for(int j = i; j<n; j+=k){
                    if(b[j] != -1 && b[j] != val){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
            ans[a[i]]++;
            if(val != -1) ans[val]--;
        }
        else{
            for(int j = i; j<n; j+=k){
                if(b[j] != -1 && b[j] != a[j]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }

    for(auto i: ans){
        if(i<0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;


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

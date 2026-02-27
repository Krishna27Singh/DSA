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
if two numbers are prime and they are not in sorted order -> alice always wins

*/

const int MAXI = 1000005;
vector<int> mini(MAXI); 
vector<int> val(MAXI);

void calc(){
    for(int i = 2; i < MAXI; i++) {
        mini[i] = i;
    } 
    for(int i=2; i*i<MAXI; i++) {
        if(mini[i] == i) {
            for(int j = i*i; j < MAXI; j += i) {
                if(mini[j] == j) {
                    mini[j] = i;
                }
            }
        }
    }
    val[1] = 1; 
    for(int i = 2; i < MAXI; i++) {
        int temp = i;
        int p = mini[temp];
        bool flag = true;
        while(temp > 1) {
            if (mini[temp] != p) {
                flag = false;
                break;
            }
            temp /= mini[temp];
        }
        if(flag) val[i] = p;
        else val[i] = -1;
    }
}


void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    
    if(is_sorted(all(a))) {
        cout<<"Bob"<<endl;
        return;
    }
    
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(val[a[i]] == -1) {
            flag = false;
            break;
        }
    }
    
    if(!flag) {
        cout<<"Alice"<<endl;
        return;
    }
    
    bool ok = true;
    for(int i = 1; i < n; i++) {
        if(val[a[i]] < val[a[i-1]]) {
            ok = false;
            break;
        }
    }
    
    if(ok) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;

    

    // Output


}

/*************************************************************************************************** */

int main(){
    calc();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

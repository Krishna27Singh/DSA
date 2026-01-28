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
    vector<int> p(n);

    if(n%2 == 0){
        int temp = 4;
        int maxi = pow(2, 30);
        while(temp <= maxi){
            if(n == temp){
                cout<<-1<<endl;
                return;
            }
            if(temp>n) break;
            temp *= 2;
        }
    }

    if(n%2){
        p[0] = n-1;
        p[n-1] = 1;
        for(int i = 1; i<n-1; i++){
            if(i%2) p[i] = i+2;
            else p[i] = i;
        }
    }
    else{
        p[0] = n;
        p[n-1] = 1;
        for(int i = 1; i<n-1; i++){
            if(i%2) p[i] = i+2;
            else p[i] = i;
        }
        // for(auto it : p) cout<<it<<" ";
        // cout<<endl;
        int temp = n;
        int replace = 1;
        while(((temp>>1) & 1) == 0){
            temp = temp >> 1;
            replace++;
        }
        // cout<<replace<<endl;
        replace = pow(2, replace);
        swap(p[0], p[replace-1]);

    }

    for(auto it: p) cout<<it<<" ";
    cout<<endl;

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

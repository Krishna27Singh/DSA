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
    for(int i = 0; i<n; i++) cin>>p[i];
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> pos(n+1);
    for(int i = 0; i<n; i++){
        pos[p[i]] = i;
    }

    int last = -1;
    for(int i = 0; i < n; ){
        int j = i;
        int x = a[i];
        int curr = pos[x];
        if(curr <= last){
            cout<<"NO"<<endl;
            return;
        }
        last = curr;
        while(j+1<n && a[j+1] == a[i]) j++;
        // if(pos[x]<i-1 || pos[x]>j+1){
        //     cout << "NO"<<endl;
        //     return;
        // }
        i = j+1;
    }
    cout<<"YES"<<endl;
    return;


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

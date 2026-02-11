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
n flowers are there with 
ai -> beauty of ith flower

choose m flowers
iterater from left to right
take / not take
ai >= bi

operation ->
choose minimum integer k and place it anywhere
 
*/

void solve(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(m);
    for(int i = 0; i<m; i++) cin>>b[i];

    int ptr1 = 0;
    int ptr2 = 0;
    int cnt = 0;
    while(ptr1 < n && ptr2 < m){
        if(a[ptr1] >= b[ptr2]){
            cnt++;
            ptr1++;
            ptr2++;
        }
        else ptr1++;
    }

    if(cnt >= m){
        cout<<0<<endl;
        return;
    }

    cout<<1<<endl;

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

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
operation -> choose index i and flip all the bits except i

each index must be choose atmost 1
max operations -> n

make all bits 0
number of operations
indices to flip
or -1 if not possible

*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    int cnt1 = 0;
    for(auto i: s) if(i == '1') cnt1++;
    int cnt0 = n-cnt1;
    if(cnt1 == 0){
        cout<<0<<endl;
    }
    if(cnt1 % 2 == 0){
        cout<<cnt1<<endl;
        for(int i = 0; i<n; i++) if(s[i] == '1') cout<<i+1<<" ";
        cout<<endl;
        return;
    }

    if(cnt0 % 2 != 0){
        cout<<cnt0<<endl;
        for(int i = 0; i<n; i++) if(s[i] == '0') cout<<i+1<<" ";
        cout<<endl;
        return;
    }

    cout<<-1<<endl;

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

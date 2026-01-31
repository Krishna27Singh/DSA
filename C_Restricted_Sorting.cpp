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
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> sortedA(a.begin(), a.end());
    sort(sortedA.begin(), sortedA.end());

    if(is_sorted(a.begin(), a.end())){
        cout<<-1<<endl;
        return;
    }

    int maxi = sortedA[n-1];
    int mini = sortedA[0];
    int k = INT_MAX;
    for(int i = 0; i<n; i++){
        if(a[i] == sortedA[i]) continue;
        k = min(k, max(abs(sortedA[i]-a[i]), 
        max(max(min(abs(mini-a[i]), abs(mini-sortedA[i])), min(abs(maxi-a[i]), abs(maxi-sortedA[i]))),
        max(min(abs(a[i]-mini), abs(sortedA[i]-maxi)), min(abs(a[i]-maxi), abs(sortedA[i]-mini))))));
    }

    // for(auto i: a) cout<<i<<" ";
    // cout<<endl
    // for(auto i: sortedA) cout<<i<<" ";
    // cout<<endl;

    cout<<k<<endl;
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

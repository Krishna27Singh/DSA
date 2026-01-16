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
    int n, m; cin>>n>>m;
    vector<int> a(m); 
    for(int i = 0; i<m; i++) cin>>a[i];

    sort(a.begin(), a.end());
    int left = 0;
    int right = m-1;

    int it = n;
    while(it>0){
        for(int i = 0; i<6; i++){
            if(i%2==0) cout<<a[left]<<" ";
            else cout<<a[right]<<" ";
        }
        cout<<endl;
        it--;
        if(it<=0) break;
        for(int i = 0; i<6; i++){
            if(i%2==0) cout<<a[right]<<" ";
            else cout<<a[left]<<" ";
        }
        cout<<endl;
        left++;
        right--;
        it--;
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

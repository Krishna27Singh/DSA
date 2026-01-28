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
    int n, c; cin>>n>>c;
    string s; cin>>s;
    

    if(s[0] == '0' || s[n-1] == '0'){
        cout<<-1<<endl;
        return;
    }

    ll ans = 2;
    ll temp = 2;
    for(int i = 1; i<n-1; i++){
        if(s[i] == '1'){
            ans = (ans*2)%MOD;
            temp = (temp*2)%c;
        }
        else{
            ans = (ans*i)%MOD;
            temp = (temp*i)%c;
        }
    }

    
    if(temp) cout<<ans<<endl;
    else cout<<-1<<endl;

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

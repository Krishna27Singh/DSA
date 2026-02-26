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
bit position which are not set in m should also be not set ai
bit position can be set/not set at set bit positions of m


*/

void solve(){
    int s, m; cin>>s>>m;

    if(s <= m){
        cout<<1<<endl;
        return;
    }

    int ans = 0;
    int bits = 0;
    int n = m;
    while (n > 0) {
        bits++;
        n >>= 1;
    }
    vector<int> positions;                                   
    for(int bit = 0; bit<bits; bit++){
        if((m>>bit)&1) positions.push_back(bit);
    }
    reverse(all(positions));
    for(auto i: positions) cout<<i<<endl;

    for(auto bit : positions){
        cout<<"bit: "<<bit<<endl;
        cout<<"S: "<<s<<endl;
        while(s > 0){
            cout<<s<<endl;
            // cout<<(m-(1<<bit))<<endl;
            // cout<<(1<<bit)<<endl;
            // cout<<"exe1"<<endl;
            s -= (1<<bit);
            ans++;
        }
        if( s == 0){
            cout<<ans<<endl;
            return;
        }
        if(s < 0){
            s += (1<<bit);
            ans--;
        }
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

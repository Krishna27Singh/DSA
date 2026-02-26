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

int sum(ll x){
    int ans = 0;
    while(x){
        int dig = x%10;
        ans += dig;
        x /= 10;
    }
    return ans;
}

void solve(){
    ll x; cin>>x;
    ll ans = 0;
    vector<pair<ll, ll>> digIdx;
    ll idx = 0;
    ll temp = x;
    ll sum = 0;
    while(temp){
        ll dig = temp%10;
        sum += dig;
        digIdx.push_back(mp(dig, idx));
        temp /= 10;
        idx++;
    }
    if(sum < 10){
        cout<<0<<endl;
        return;
    }
    ll move = 0;
    // cout<<"idx: "<<idx<<endl;
    // cout<<"sum: "<<sum<<endl;
    sort(digIdx.begin(), digIdx.end());
    reverse(digIdx.begin(), digIdx.end());
    // for(auto i: digIdx) cout<<i.first<<" "<<i.second<<endl;
    ll len = digIdx.size();
    for(int i = 0; i<len; i++){
        // cout<<"sum: "<<sum<<" move: "<<move<<endl;
        if(sum < 10){
            cout<<move<<endl;
            return;
        }
        if(digIdx[i].second != idx-1){
            sum -= digIdx[i].first;
        }
        else{
            if(i+1 < len && digIdx[i+1].first == digIdx[i].first){
                digIdx[i+1].second = idx-1;
                sum -= digIdx[i].first;
                // cout<<"sum: "<<sum<<endl;
            }
            else{
                sum -= (digIdx[i].first-1);
                // cout<<"sum: "<<sum<<endl;
            }
        }
        move++;
    }

    cout<<move<<endl;
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

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

/*
****************************************** Testing ****************************************************
4, 3
4, 4 -> 2, 2                                   
*/

pair<ll,ll> query2(ll start, ll len, ll i, ll j, ll d){
    if(len == 2){
        if(d == start) return {i, j};
        if(d == start + 1) return {i+1, j+1};
        if(d == start + 2) return {i+1, j};
        return {i, j+1};
    }

    ll half = len / 2;
    ll block = half * half;

    if(d < start + block)
        return query2(start, half, i, j, d);

    if(d < start + 2*block)
        return query2(start + block, half, i + half, j + half, d);

    if(d < start + 3*block)
        return query2(start + 2*block, half, i + half, j, d);

    return query2(start + 3*block, half, i, j + half, d);
}

ll query1(ll start, ll len, ll i, ll j, ll x, ll y){
    if(len == 2){
        if(x == i && y == j) return start;
        if(x == i+1 && y == j+1) return start + 1;
        if(x == i+1 && y == j) return start + 2;
        if(x == i && y == j+1) return start + 3;
    }

    ll half = len / 2;
    ll block = half * half;

    if(x < i + half && y < j + half)
        return query1(start, half, i, j, x, y);

    if(x >= i + half && y >= j + half)
        return query1(start + block, half, i + half, j + half, x, y);

    if(x >= i + half && y < j + half)
        return query1(start + 2*block, half, i + half, j, x, y);

    return query1(start + 3*block, half, i, j + half, x, y);
}

void solve(){
    ll n, q; cin>>n>>q;
    while(q--){
        string s; cin>>s;
        if(s == "->"){
            ll x, y; cin>>x>>y;
            cout<<query1(1, (1<<n), 1, 1, x, y)<<endl;
        }
        else{
            ll d; cin>>d;
            pair<ll, ll> ans = query2(1, (1<<n), 1, 1, d);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
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

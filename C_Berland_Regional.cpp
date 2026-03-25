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
n universities
n students
ith student is enrolled in the ui university
ith student skill level is si
strenght -> sum of skills of all members of all the teams
strength of region for k from 1 to n

strongest -> second strongest -> third strongest
*/

/*
****************************************** Testing ****************************************************


6
3 3 3 3 3 3
5 9 6 7 9 7

7
1 2 1 2 1 2 1
6 8 3 1 5 1 5

1 -> 6 5 5 3
2 -> 8 1 1

6 + 5 + 5 + 3 + 8 + 1 + 1 
(6+5) + (5+3) + (8+1) 
(6+5+5) + (8+1+1) 
(6+5+5+3)

k = 1

k = 2

k = 3

k = 4

store in map
calculate prefix sum for each






*/

void solve(){
    ll n; cin>>n;
    vector<ll> u(n);
    for(int i = 0; i<n; i++) cin>>u[i];
    vector<ll> s(n);
    for(int i = 0; i<n; i++) cin>>s[i];

    unordered_map<ll, vector<ll>> mpp;
    for(int i = 0; i<n; i++) mpp[u[i]].pb(s[i]);

    vector<ll> final(n, 0);
    for(auto it : mpp){
        auto uni = it.first;
        auto si = it.second;
        int l = si.size();
        sort(all(si)); reverse(all(si));
        vector<ll> prefix(l, 0);
        prefix[0] = si[0];
        for(int i = 1; i<l; i++) prefix[i] = si[i] + prefix[i-1];
        int k = 1;
        while(k<=l){
            final[k-1] += prefix[(l/k)*k - 1];
            k++;
        }
    }

    for(auto i: final) cout<<i<<" ";
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

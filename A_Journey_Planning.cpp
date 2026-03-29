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
choose cities in increasing order -> c1, c2, c3, ... ck
cities -> 1, 2, 3, .... n
such that c(i+1) - c(i) = b(c(i+1)) - b(c(i))
maximum possible beauty -> sum of all the respective beauty values of ci 


*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    unordered_map<int, vector<int>> mpp;

    for(int i = 0; i<n; i++){
        mpp[b[i] - i].pb(b[i]);
    }

    int ans = 0;

    for(auto it : mpp){
        auto beauties = it.second;
        int sum = 0;
        for(auto it : beauties) sum += it;
        ans = max(ans, sum);
    }

    cout<<ans<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

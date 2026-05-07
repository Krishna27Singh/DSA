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

*/

void solve(){
    int n; 
    cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) cnt++;
    }

    if(cnt > 1 || (cnt == 1 && n % 2 == 0) || (cnt == 0 && n % 2)){
        cout << -1 << '\n';
        return;
    }

    unordered_map<int,int> mpp;

    for(int i = 0; i < n; i++){
        mpp[a[i]] = b[i];
    }

    for(auto x : mpp){
        if(mpp[x.second] != x.first){
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> pos(n + 1);

    for(int i = 0; i < n; i++){
        pos[a[i]] = i;
    }

    vector<pair<int,int>> ans;

    auto work = [&](int x, int y){
        if(x == y) return;
        ans.pb({x, y});
        swap(a[x], a[y]);
        swap(b[x], b[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
    };

    if(cnt == 1){
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                work(i, n / 2);
                break;
            }
        }
    }

    for(int i = 0; i < n / 2; i++){
        int need = b[i];
        int j = pos[need];
        work(j, n - 1 - i);
    }

    cout << sz(ans) << '\n';
    for(auto [x, y] : ans){
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
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

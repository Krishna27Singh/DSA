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

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<ll> pre(n), suf(n + 1);
    pre[0] = abs(a[0]);
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + abs(a[i]);
    
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    ll best = suf[0];
    int idx = -1;
    for (int i = 1; i < n; i++){
        if (a[i] > 0){
            ll score = pre[i - 1] + suf[i + 1] - a[i];
            if (score > best){
                best = score;
                idx = i;
            }
        }
    }

    if (idx == -1){
        cout << "0\n";
        return;
    }

    vector<int> ans;
    for (int i = idx - 1; i >= 0; i--){
        if (ans.size() & 1)
            a[i] = -a[i];
        if (a[i] > 0)
            ans.push_back(i);
    }
    ans.push_back(idx);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];

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

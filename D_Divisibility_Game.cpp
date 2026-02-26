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
a -> choose number x -> y%x == 0
y -> choose number y -> y%x != 0
y is removed from the array b

win?


*/

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b(m);
    int max_b = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] > max_b) max_b = b[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int unique_a_count = a.size();

    vector<int> div_count(max_b + 1, 0);
    for (int x : a) {
        if (x > max_b) break; 
        for (int mult = x; mult <= max_b; mult += x) {
            div_count[mult]++;
        }
    }

    int aliceExtra = 0;
    int bobExtra = 0;
    int game = 0;

    for (int i = 0; i < m; i++) {
        int cnt = div_count[b[i]];
        if (cnt == unique_a_count) {
            aliceExtra++; 
        } else if (cnt > 0) {
            game++;       
        } else {
            bobExtra++;   
        }
    }

    int alice_score = aliceExtra + (game + 1) / 2;
    int bob_score = bobExtra + game / 2;

    if (alice_score > bob_score) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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

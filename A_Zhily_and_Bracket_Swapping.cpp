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
        int n; cin >> n;
		string s, t, r1 = "", r2 = "";
		cin >> s >> t;
		bool bj = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) r1 += s[i], r2 += t[i];
			else {
				if (bj) r1 += '(', r2 += ')';
				else r1 += ')', r2 += '(';
				bj ^= 1;
			}
		}
		int t1 = 0, t2 = 0;
		bj = 1;
		for (int i = 0; i < n; i++) {
			if (r1[i] == '(') ++t1; else --t1;
			if (r2[i] == '(') ++t2; else --t2;
			if (t1 < 0 || t2 < 0) bj = 0;
		}
		if (t1 != 0 || t2 != 0) bj = 0;
		if (bj) cout << "YES\n";
		else cout << "NO\n";

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

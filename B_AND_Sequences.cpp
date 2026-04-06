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
number of arrangements of ai's such that 

a0 & a1 & .. & ai = ai+1 & ai+2 & .. & an-1

*/

/*
****************************************** Testing ****************************************************

*/

const int N = 200000;            
int fact[N + 1];                 

void solve() {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		int totalAnd = a[0];
		for (int i = 1; i < n; i++) { 
				totalAnd &= a[i];
		}

		int countAnd = count(a, a + n, totalAnd); 
		if (countAnd <= 1) { 
				cout << 0 << "\n";
				return;
		}

		cout << 1LL * countAnd * (countAnd - 1) % MOD * fact[n - 2] % MOD << '\n';
}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fact[0] = 1;
		for (int i = 1; i <= N; i++) { 
				fact[i] = (1LL * fact[i - 1] * i) % MOD;
		}

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
    return 0;
}

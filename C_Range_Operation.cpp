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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin >> n;
		vector<int> a(n);
		ll sum = 0, ans = 0;
		ll mx_val = 0;
		for(int i = 1; i <= n; i++) {
			mx_val = max(mx_val, -(ll)i*i + i + sum);
			cin >> a[i-1]; sum += a[i-1];
			ans = max(ans, (ll)i*i + i - sum + mx_val);
		}
		cout << ans + sum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

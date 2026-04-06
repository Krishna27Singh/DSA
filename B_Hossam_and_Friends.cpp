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
1 2 3 4 .... n

m pair of friends don't know each other
good -> only if every pair is a friend
number of segments (a, b) such that the segment is good

1 2 3 4 
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, m;
		cin >> n >> m;

		vector<int> nearestEnemy(n + 1, 0);

		for (int i = 0; i < m; i++) {
				int a, b;
				cin >> a >> b;
				if (a > b) swap(a, b); 
				nearestEnemy[b] = max(nearestEnemy[b], a); 
		}

		vector<int> maxLeft(n + 1);

		maxLeft[1] = 1; 

		long long ans = 1; 

		for (int i = 2; i <= n; i++) {
				maxLeft[i] = max(maxLeft[i - 1], nearestEnemy[i] + 1);
				ans += i - maxLeft[i] + 1;
		}

		cout << ans << '\n';



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

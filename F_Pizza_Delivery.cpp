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
start from (Ax, Ay) -> deliver -> (Bx, By)
cases. each move 1 sec
(𝑥+1,𝑦), 
(𝑥,𝑦+1), 
(𝑥,𝑦−1)

O(N) | O(NlogN)

need to try out all possible paths right

start -> end

keep track of all visited paths

0 -> we entered at the bottomost point and we leave from the topmost point
1 -> we entered at the topmost point and we leave from the bottomost point

*/

// int f(int idx, int pos, unordered_map<int, set<int>> &plane){


//     // 
//     int case1 = INF; int case2 = INF;
//     if(pos == 1){
//         case1 = 
//     }
// }

ll dist(pair<ll, ll> p1, pair<ll, ll> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void solve(){
    ll n, sx, sy, ex, ey; cin >> n >> sx >> sy >> ex >> ey;
		map<ll, ll> top, bot;
		top[sx] = bot[sx] = sy;
		top[ex] = bot[ex] = ey;
 
		vector<ll> xc(n), yc(n);
		for(auto &x : xc) cin >> x;
		for(auto &y : yc) cin >> y;
 
		for(ll i = 0; i < n; i++) {
			if(!top.count(xc[i])) {
				top[xc[i]] = bot[xc[i]] = yc[i];
				continue;
			}
			top[xc[i]] = max(top[xc[i]], yc[i]);
			bot[xc[i]] = min(bot[xc[i]], yc[i]);
		}
 
		vector<pair<ll, ll>> top_pts, bot_pts;
		for(auto &[x, y] : top) {
			top_pts.push_back({x, y});
		}
		for(auto &[x, y] : bot) {
			bot_pts.push_back({x, y});
		}
 
		n = top_pts.size();
		vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX/10));
		dp[0][0] = dp[0][1] = 0;
		for(ll i = 1; i < n; i++) {
			for(ll j = 0; j < 2; j++) {
				for(ll k = 0; k < 2; k++) {
					auto prev_pt = (k ? top_pts[i-1] : bot_pts[i-1]);
					auto cur_pt = (j ? bot_pts[i] : top_pts[i]);
					dp[i][j] = min(dp[i][j], dp[i-1][k] + dist(prev_pt, cur_pt) + top_pts[i].second - bot_pts[i].second);
				}
			}
		}
		cout << dp[n-1][0] << "\n";

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

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
standing at an index, we can either take that person in the elevator or not take that person in the elevator
I need to maintain the sum of the current people in that elevator and it should not exceed x

maximum sum can be upto 2e10
if i maintain dp states i, sum. the tc will go upto 4e11

what the problem is? 
we can't store sum as a state

*/

void solve(){
    int n, x; cin >> n >> x;
    int peopleWeights[n];
    for (auto &x : peopleWeights) cin >> x;
    vector <pair <int, int>> dp (1 << n);
    dp[0] = {1, 0};
    for (int subset = 1; subset < (1 << n); subset++) {
        dp[subset] = {21, 0};
        for (int person = 0; person < n; person++) {
            if ((subset >> person) & 1) {
                auto [rides, weight] = dp[subset ^ (1 << person)];
                if (weight + peopleWeights[person] > x) {
                    rides++;
                    weight = min (peopleWeights[person], weight);
                }
                else weight += peopleWeights[person];
                dp[subset] = min (dp[subset], {rides, weight});
            }
        }
    }
    cout << dp[(1 << n) - 1].first;

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

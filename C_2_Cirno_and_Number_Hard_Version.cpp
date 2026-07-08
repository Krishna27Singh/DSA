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
****************************************** Helper Function *******************************************
Instead of stoull or try-catch, we manually parse the string into an unsigned long long
and update the minimum difference.
*/
void check(string s, ull a, ull &min_diff) {
    if (s == "") return;
    
    ull cand = 0;
    for (int i = 0; i < s.length(); i++) {
        cand = cand * 10 + (s[i] - '0');
    }
    
    ull diff;
    if (cand > a) diff = cand - a;
    else diff = a - cand;
    
    if (diff < min_diff) {
        min_diff = diff;
    }
}

/*
****************************************** APPROACH **************************************************
Generate all boundary candidates instead of acting greedily:
1. Candidate with 1 fewer digit (all maxi).
2. Candidate with 1 more digit (smallest non-zero digit + all mini).
3. Same length candidates (Branch Up & Branch Down on every digit index).
*/

void solve(){
    ll a, n; 
    cin >> a >> n;
    
    vector<int> d(n);
    vector<int> mpp(10, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        mpp[d[i]]++;
    }

    int mini = d[0];
    int maxi = d[n - 1];
    
    int minNon0 = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] > 0) {
            minNon0 = d[i];
            break;
        }
    }

    string S = to_string(a);
    int len = S.length();
    ull minD = ULLONG_MAX;
    ull ua = a; 

    if (len > 1) {
        string s = "";
        for (int i = 0; i < len - 1; i++) s += (char)('0' + maxi);
        check(s, ua, minD);
    }

    // 2. Longer length candidate (e.g., if a=99, try 100)
    if (minNon0 != -1) {
        string s = "";
        s += (char)('0' + minNon0);
        for (int i = 0; i < len; i++) s += (char)('0' + mini);
        check(s, ua, minD);
    }

    string prefix = "";
    for (int i = 0; i < len; i++) {
        int cur = S[i] - '0';

        int v1 = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (d[j] < cur) {
                v1 = d[j];
                break;
            }
        }
        if (v1 != -1) {
            string s = prefix;
            s += (char)('0' + v1);
            for (int j = 0; j < len - 1 - i; j++) s += (char)('0' + maxi);
            check(s, ua, minD);
        }

        int v2 = -1;
        for (int j = 0; j < n; j++) {
            if (d[j] > cur) {
                v2 = d[j];
                break;
            }
        }
        if (v2 != -1) {
            string s = prefix;
            s += (char)('0' + v2);
            for (int j = 0; j < len - 1 - i; j++) s += (char)('0' + mini);
            check(s, ua, minD);
        }

        if (mpp[cur]) {
            prefix += (char)('0' + cur);
        } else {
            break; 
        }
    }

    if (prefix.length() == len) {
        check(prefix, ua, minD);
    }

    cout << minD << "\n";
}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1; cin >> tc;
    while (tc--) solve();
    return 0;
}
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
using i128 = __int128_t;

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
94247459

6 7 


*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    long long a;
    int n; 
    cin >> a >> n;
    int d1, d2;
    cin >> d1 >> d2;

    string s = to_string(a);
    int L = s.length();
    char c1 = '0' + d1;
    char c2 = '0' + d2;

    vector<long long> candidates;

    auto add_candidate = [&](string cand) {
        if (cand.empty()) return;
        if (cand.length() > 1 && cand[0] == '0') return;
        candidates.push_back(stoll(cand));
    };

    if (L > 1) {
        string cand(L - 1, c2);
        add_candidate(cand);
    }

    string cand_plus;
    if (d1 == 0) {
        cand_plus += c2;
        cand_plus += string(L, c1);
    } else {
        cand_plus = string(L + 1, c1);
    }
    add_candidate(cand_plus);

    string pref = "";
    bool perfectly_matched = true;
    
    for (int i = 0; i < L; ++i) {
        if (c1 != s[i]) {
            string temp = pref + c1;
            if (c1 < s[i]) temp += string(L - 1 - i, c2); // Pad max
            else temp += string(L - 1 - i, c1);           // Pad min
            add_candidate(temp);
        }
        
        if (c2 != s[i]) {
            string temp = pref + c2;
            if (c2 < s[i]) temp += string(L - 1 - i, c2); // Pad max
            else temp += string(L - 1 - i, c1);           // Pad min
            add_candidate(temp);
        }

        if (s[i] == c1 || s[i] == c2) {
            pref += s[i];
        } else {
            perfectly_matched = false;
            break;
        }
    }
    
    if (perfectly_matched) {
        add_candidate(pref);
    }

    long long min_diff = -1;
    for (long long cand : candidates) {
        long long diff = abs(a - cand);
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << "\n";
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

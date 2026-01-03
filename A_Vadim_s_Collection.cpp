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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    string s; cin>>s;

    vector<int> freq(10, 0);
    for (char c : s) {
        freq[c - '0']++;
    }

    string ans = "";

    for (int i = 0; i < 10; i++) {
        int need = 9 - i; 
        for (int d = need; d <= 9; d++) {
            if (freq[d] > 0) {
                ans.push_back(char('0' + d));
                freq[d]--;
                break;
            }
        }
    }

    cout<<ans<<endl;


    // Output

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

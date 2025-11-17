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
    string s; cin>>s;
    int n = s.size();

    int c1 = 0, c2 = 0, c3 = 0; 
		for(int i = 0; i < n; i++) {
			if(s[i] == '<') c1++;
			else if(s[i] == '*') c2++;
			else c3++;
		}
		string chk = string(c1, '<') + string(c2, '*') + string(c3, '>');
		if(c2 > 1 || chk != s) cout << "-1\n";
		else cout << max(c1+c2, c2+c3) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

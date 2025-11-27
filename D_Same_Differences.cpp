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
    int n;
		cin >> n; 
		vector<int> v(n); 

		for (int i = 0; i < n; i++)
		{
			cin >> v[i]; 

			v[i] -= i; 
		} 
		map<long long, long long> freq; 
		for (int i = 0; i < n; i++) 
			freq[v[i]]++; 
		long long ans = 0; 
		for (auto &[val, count] : freq)
		{
			ans += ((count) * (count - 1)) / 2; 
		}

		cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

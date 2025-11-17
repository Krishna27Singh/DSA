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
    int n, s; cin>>n>>s;
    vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i]; 

		int len = -1;

		map<int, int> mp; 

		mp[0] = -1; 

		int sum = 0; 
		for (int i = 0; i < n; i++)
		{
			sum += v[i];
			if (mp.count(sum - s))
			{
				len = max(len, i - mp[sum - s]); 
			}

			if (!mp.count(sum))
			{
				mp[sum] = i; 
			}
		} 
		if (len == -1)
		{
			cout << "-1\n";
		}
		else
		{
			cout << (n - len) << "\n";
		}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

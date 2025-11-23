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
        int n; cin>>n; string s; cin>>s;
        int ans = INT_MAX; 

		for (char c = 'a'; c <= 'z'; c++)
		{
			int tmp = 0; 
			bool isPoss = true; 

			int i = 0, j = n - 1; 
			while (i < j)
			{
				if (s[i] == s[j])
				{
					i++; 
					j--; 
					continue; 
				}

				if (s[i] == c)
				{
					tmp++; 
					i++; 
				}
				else if (s[j] == c)
				{
					tmp++; 
					j--; 
				}
				else
				{
					isPoss = false; 
					break; 
				}
			} 

			if (!isPoss)
				tmp = INT_MAX; 

			ans = min(ans, tmp); 
		} 

		if (ans == INT_MAX)
			ans = -1; 

		cout << ans <<endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

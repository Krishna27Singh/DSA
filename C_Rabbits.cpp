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

ll n;
string s;
 
const int N = 2e5+1;
ll DP[N][3][3];

bool dp(ll i, ll l, ll sl)
{
	if(i == n)
	{
		if(sl == 2 && l == 0) return false;
		return true;
	}
	if(DP[i][l][sl] != -1) return DP[i][l][sl];
	ll ans = false;
 
	if(s[i] == '1')
	{
		if(sl == 2 && l == 0)
		{
			ans = false;
			return DP[i][l][sl] = ans;
		}
		ans |= dp(i+1, 0, l);
		return DP[i][l][sl] = ans;
	}
	if(l == 0 && sl == 2) 
	{
		ans |= dp(i+1, 1, 0);
		return DP[i][l][sl] = ans;
	}
	if(l == 0) ans |= dp(i+1, 2, 0);
	if(l == 1 || l == 2) 
	{
		ans |= dp(i+1, 1, l);
		ans |= dp(i+1, 2, l);
	}
 
	return DP[i][l][sl] = ans;
}

void solve(){
    cin>>n; cin>>s;

    for(ll i = 0 ; i <= n ; i++)
		{
			for(ll j = 0 ; j < 3 ; j++)
			{
				for(ll k = 0 ; k < 3 ; k++)
				{
					DP[i][j][k] = -1;
				}
			}
		}
		bool check = dp(0, 1, 1) ;
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;

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

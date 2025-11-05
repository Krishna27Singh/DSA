#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    int n;
		cin >> n;

		string s;
		cin >> s; 

		long long ans = 0; 
		vector<bool> isRemoved(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				if (s[j - 1] == '1')
					break;

				if (isRemoved[j])
					continue;
				else
				{
					isRemoved[j] = true;
					ans += i;
				}
			}
		} 

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

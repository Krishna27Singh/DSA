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
		vector<vector<char>> mat(n, vector<char>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		} 

		int ans = 0; 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int c0 = 0, c1 = 0; 
				if (mat[i][j] == '0')
					c0++;
				else
					c1++;

				if (mat[j][n - i - 1] == '0')
					c0++;
				else
					c1++;

				if (mat[n - i - 1][n - j - 1] == '0')
					c0++;
				else
					c1++;

				if (mat[n - j - 1][i] == '0')
					c0++;
				else
					c1++;

				if ((c0 == 0) or (c1 == 0))
					continue;

				if (c0 >= c1)
				{
					ans += c1;
					mat[i][j] = '0';
					mat[j][n - i - 1] = '0';
					mat[n - i - 1][n - j - 1] = '0';
					mat[n - j - 1][i] = '0';
				}
				else
				{
					ans += c0;
					mat[i][j] = '1';
					mat[j][n - i - 1] = '1';
					mat[n - i - 1][n - j - 1] = '1';
					mat[n - j - 1][i] = '1';
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

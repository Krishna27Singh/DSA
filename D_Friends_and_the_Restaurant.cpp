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
    int n; cin>>n;
    vector<int> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    vector<int> y(n);
    for(int i = 0; i<n; i++) cin>>y[i];

    multiset<int> ms; 

		for (int i = 0; i < n; i++)
			ms.insert(y[i] - x[i]); 

		int ans = 0;

		while (ms.size() > 1) 
		{
			int val1 = *ms.begin(); 
			ms.erase(ms.begin()); 

			auto it = ms.lower_bound(-val1); 

			if (it == ms.end())
				continue; 

			ans++; 
			ms.erase(it); 
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

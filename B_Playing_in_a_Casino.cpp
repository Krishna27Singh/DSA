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
    int n, m; cin>>n>>m;
    vector<vector<int> > v(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }

    long long ans = 0;
    for(int j = 0; j<m; j++){
        vector<int> newV;
        for(int i = 0; i<n; i++){
            newV.push_back(v[i][j]);
        }
        sort(newV.begin(), newV.end());
        vector<long long> prefixSum(n+1, 0);
        for(int i = 1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + newV[i-1];
        }

        for(int i = n-1; i>=0; i--){
            ans += i*newV[i] - prefixSum[i];
        }
            
    }
    cout<<ans<<endl;
    
    }




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

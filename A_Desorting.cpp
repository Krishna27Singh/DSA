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
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    if(!is_sorted(a.begin(), a.end())){
        cout<<0<<endl;
        return;
    }

    int ans = INT_MAX;

    for(int i = 0; i<n-1; i++){
        ans = min(ans, abs(a[i]-a[i+1])/2 + 1);
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

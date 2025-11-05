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

    int ans = INT_MIN;
    int idx = 0;
    for(; idx<n; idx++) {
        if(a[idx] == 1) break;
    }
    ans = max(ans, idx);

    int count = 0;
    for(int i = idx; i<n-1; i++){
        if(a[i+1]==1){
            ans = max(ans, count);
            count = 0;
            continue;
        }
        else count++;
    }

    ans = max(ans, count);
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

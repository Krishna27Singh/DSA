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

    if(n%2!=0){
        int ans = a[0];
        for(int i = 1; i<n; i++){
            ans = ans ^ a[i];
        }
        if(ans < 256) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    else{
        int ans = a[0];
        for(int i = 1; i<n; i++){
            ans = ans ^ a[i];
        }
        if(ans) cout<<-1<<endl;
        else cout<<0<<endl;
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

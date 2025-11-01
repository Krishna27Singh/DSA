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
    int n, r, b; cin>>n>>r>>b;
    int rs = r/(b+1);
    string ans = "";
    int count = r%(b+1);
    for(int i = 0; i<b; i++){
        for(int j = 0; j<rs; j++) ans.push_back('R');
        if(count){
            ans.push_back('R');
            count--;
        }
        ans.push_back('B');
    }
    int m = ans.size();
    for(int i = 0; i<n-m; i++){
        ans.push_back('R');
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

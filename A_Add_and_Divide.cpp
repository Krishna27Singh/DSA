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
    int a, b; cin>>a>>b;

    int ans = 0;
    bool check = false;
    int i = 0;
    while(true){
        int count = 1 + i;
        int value = b + i;
        while(value*value <= a){
            value *= value;
            count++;
        }

        if(count>ans) break;

        ans = min(ans, count);
        i++;
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

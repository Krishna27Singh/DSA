#include <iostream>
#pragma GCC optimize("O3")
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int inf = 1e15;
const int mod = 998244353;

inline void solve(){
    
    // m * n = s * k 

    int s, m;
    cin >> s >> m;

    if(s % (m & -m)){
        cout << -1;
        return;
    }

    bool ok = 1;
    int ans = 0;

    for(int bit = 0;bit < 64;bit += 1){
        int cur = (1ll << (bit)) - 1;

        
        int ss = (s & cur);
        int mm = (m & cur);

        if(ss == 0) continue;

        ans = max(ans, (ss + mm - 1)/mm);
    }

    cout << ans;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    return 0;
}

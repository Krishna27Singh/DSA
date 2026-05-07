#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <numeric>
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
        int n,m;cin>>n>>m;
        map<ll,ll>cnt;
        auto isqrt=[&](ll x)
        {
            ll val=sqrtl(x)+5;
            while(val*val>x)val--;
            return val;
        };
        vector<ll>a(n),r(n);
        for(ll&i:a)cin>>i;
        for(ll&i:r)cin>>i;
        for(int i=0;i<n;i++)
        {
            ll aa=a[i],rr=r[i];
            for(ll x=aa-rr;x<=aa+rr;x++)
            {
                cnt[x]=max(cnt[x],2*isqrt(rr*rr-(x-aa)*(x-aa))+1);
            }
        }
        ll ans=0;
        for(auto[x,c]:cnt)ans+=c;
        cout<<ans<<"\n";

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

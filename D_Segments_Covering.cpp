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
m cells
any segment can be assigned to the cells
as long as atleast on of l or r lie in the range from 1 to m
condition -> l<1 && >=1 or l<=n && r > n

3 3
1 2 1 3
3 3 1 2
1 3 2 3

can't there be multiple probabilities

Try out all possible ways

if im standing at an index and it is where r of a segment is then there must exist and l = r+1

store all the left values at the same index

f(x) -> probability that cells from 1 -> x-1 are perfectly covered

dp[x] -> probability that cells from 1 -> x-1 are perfectly covered
dp[0] = 1
# iterate over all segments such that ri = x
CONDITION
1) dp[l-1]
2) pi/qi
3) l is in between li and ri. 
   all such segments like this should not occur



*/


void solve(){
    int n, m; cin>>n>>m;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> p(n);
    vector<int> q(n);
    for(int i = 0; i<n; i++){
        cin>>l[i]>>r[i]>>p[i]>>q[i];
    }

    unordered_map<int, int> left;
    for(int i = 0; i<n; i++) left[l[i]]++;
    unordered_map<int, int> right;
    for(int i = 0; i<n; i++) right[r[i]]++;
    
    if((left.find(1) == left.end()) || (right.find(m) == right.end())){
        cout<<0<<endl;
        return;
    }

    vector<pair<pair<int, int>, pair<int, int>>> lrpq;
    for(int i = 0; i<n; i++) lrpq.pb(mp(mp(l[i], r[i]), mp(p[i], q[i])));
    sort(lrpq.begin(), lrpq.end(),
     [](const pair<pair<int,int>, pair<int,int>>& a,
        const pair<pair<int,int>, pair<int,int>>& b) {
         return a.first.first < b.first.first;
     });

    // for(auto i: lr) cout<<i.first<<" "<<i.second<<" ";

    vector<int> prefix(n, 0);
    for(int i = 0; i<n; i++){
        int j = i;
        int li = lrpq[i].first.first;
        int prod = 1;
        while(lrpq[j].first.first = li){
            prod *= (lrpq[j].second.first/lrpq[j].second.second);
            j++;
        }
        j--;
    }
    for(int i = 0; i<n; i++){
        if(prefix[i] == 0) prefix[i] = 1;
        else break;
    }

    

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

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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin>>a[i];

    vector<int> cnt(2*n+1);
    for(auto &x : a)cnt[x]++;

    int x = 0,y = 0,z = 0;
    for(int i = 1;i <= 2*n;i++){
        if(cnt[i] == 0)continue; 
        if(cnt[i]&1)x++;         
        else if(cnt[i]%4)y++;    
        else z++;                
    }

    int ans = x+2*y+2*z;
    if((z&1) && x == 0)ans -= 2; 
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

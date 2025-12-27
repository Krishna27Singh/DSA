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
    string r; cin>>r;
    int n = r.size();
    int ans = 0;
    if(r[0] == 'u'){
        r[0] = 's';
        ans++;
    }
    if(r[n-1] == 'u'){
        r[n-1] = 's';
        ans++;
    }
    int cnt = 0;
    vector<int> us;
    for(int i = 0; i<n; i++){
        if(r[i] == 'u'){
            cnt = 0;
            while(i<n && r[i] == 'u'){
                cnt++;
                i++;
            }
            us.push_back(cnt);
        }
    }


    for(auto i: us){
        if(i%2 !=0) ans += i/2;
        else{
            int it = i/2;
            ans += it;
        }
    }


    cout<<ans<<endl;
    // for(auto i: us) cout<<i<<" ";
    // cout<<endl;

    // Output
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

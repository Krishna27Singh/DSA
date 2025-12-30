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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    int cnt2025 = 0;
    int cnt2026 = 0;

    for(int i = 0; i<n-3; i++){
        if(s.substr(i, 4) == "2025") cnt2025++;
        if(s.substr(i, 4) == "2026") cnt2026++;
    }

    if(cnt2025!=0 && cnt2026==0){
        cout<<1<<endl;
        return;
    }

    cout<<0<<endl;

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

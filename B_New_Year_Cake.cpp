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
    int a, b; cin>>a>>b;
    int white = a;
    int dark = b;

    int ans1 = 0;

    int size = 1;

    while(white>=0 && dark>=0){
        white -= size;
        if(white<0) break;
        ans1++;
        size *= 2;
        dark -= size;
        if(dark<0) break;
        ans1++;
        size *= 2;
    }

    int ans2 = 0;

    size = 1;
    white = a;
    dark = b;
    while(white>=0 && dark>=0){
        dark -= size;
        if(dark<0) break;
        ans2++;
        size *= 2;
        white -= size;
        if(white<0) break;
        ans2++;
        size *= 2;
    }

    // cout<<"ans1: "<<ans1<<" ans2: "<<ans2<<endl;

    cout<<max(ans1, ans2)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    ll n, l, r, k; cin>>n>>l>>r>>k;

    if(n%2){
        cout<<l<<endl;
        return;
    }

    if(n == 2){
        cout<<-1<<endl;
        return;
    }

    ll lastTwo = 1;
    while(lastTwo <= l) lastTwo *= 2;
    

    if(lastTwo > r){
        cout<<-1<<endl;
        return;
    }

    if(k<=n-2){
        cout<<l<<endl;
        return;
    }

    cout<<lastTwo<<endl;
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

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
    int n, x, y; cin>>n>>x>>y;
    string s; cin>>s;
    
    x = abs(x); y = abs(y);

    if(max(x,y)>n){
        cout<<"NO"<<endl;
        return;
    }

    int diagonalRequired = min(x,y);

    if(n<diagonalRequired){
        cout<<"NO"<<endl;
        return;
    }

    int count4 = 0;
    for(auto i: s) if(i=='4') count4++;
    // cout<<"count "<<count4<<endl;
    int reachable = n-count4;
    // cout<<reachable<<endl;
    for(int i = 0; i<n-min(x,y); i++){
        reachable++;
    }

    if(max(x,y)<=reachable){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

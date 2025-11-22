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
    vector<long long> a(n+1);
    for(int i = 1; i<=n; i++) cin>>a[i];
    vector<long long> b(n+1);
    for(int i = 1; i<=n; i++) cin>>b[i];

    long long currScoreA = 0, currScoreM = 0;
    
    for(int i = 1; i<=n; i++){
        currScoreA ^= a[i];
        currScoreM ^= b[i];
    }

    if((currScoreA^currScoreM) == 0){
        cout<<"Tie"<<endl;
        return;
    }

    int msb = 63 - __builtin_clzll(currScoreA^currScoreM);
    int lastImp = -1;

    for(int i = 1; i<=n; i++){
        bool containsMsbAsOne = ((a[i]^b[i])>>msb)&1;
        if(containsMsbAsOne) lastImp = i;
    }

    if(lastImp%2!=0) cout<<"Ajisai"<<endl;
    else if(lastImp%2==0) cout<<"Mai"<<endl;
    else cout<<"Tie"<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

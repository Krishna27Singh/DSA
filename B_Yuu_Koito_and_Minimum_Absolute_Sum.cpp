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
    if(n==0){
        cout<<0<<endl;
        return;
    }
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    if(a[n-1]==-1 && a[0]==-1){
        a[n-1]=0;
        a[0]=0;
    }
    else if(a[n-1]==-1 && a[0]!=-1){
        a[n-1] = a[0];
    }
    else if(a[n-1]!=-1 && a[0]==-1){
        a[0] = a[n-1];
    }

    cout<<abs(a[n-1]-a[0])<<endl;

    for(auto i: a){
        if(i!=-1) cout<<i<<" ";
        else cout<<0<<" ";
    }

    

    cout<<endl;
    return;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

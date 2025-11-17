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
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin>>p[i];
    string x; cin>>x;

    if(x[0]=='1' || x[n-1]=='1'){
        cout<<-1<<endl;
        return;
    }

    int pos1 = -1; int posn = -1;
    for(int i = 0; i<n; i++){
        if(p[i]==1) pos1 = i;
        if(p[i]==n) posn = i;
    }

    cout<<pos1+1<<" "<<posn+1<<endl;
    cout<<0+1<<" "<<pos1+1<<endl;
    cout<<0+1<<" "<<posn+1<<endl;
    cout<<posn+1<<" "<<n<<endl;
    cout<<pos1+1<<" "<<n<<endl;
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

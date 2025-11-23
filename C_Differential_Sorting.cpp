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
    vector<long long> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    if(a[n-1]<a[n-2]){
        cout<<-1<<endl;
        return;
    }

    if(a[n-1]<0 && a[n-2]<0){
        if(is_sorted(a.begin(), a.end())) cout<<0<<endl;
        else cout<<-1<<endl;
        return;
    }

    cout<<n-2<<endl;
    for(int i = 0; i<n-2; i++){
        cout<<i+1<<" "<<n-1<<" "<<n<<endl;
    }

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

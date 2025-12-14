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
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    int totalNonZeros = 0;
    int totalSum = 0;

    for(auto i: b){
        if(i!=0) totalNonZeros++;
        totalSum += i;
    }

    if(totalSum - totalNonZeros >= n-1){
        cout<<totalNonZeros<<endl;
        return;
    }

    cout<<totalNonZeros - ((n-1) - (totalSum - totalNonZeros))<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    int n, k; cin>>n>>k;
    string s; cin>>s;

    unordered_map<char, int> mpp;
    for(auto i:s ) mpp[i]++;

    for(auto &i: mpp){
        if(k<=0) break;
        if((i.second)%2){
            i.second -= 1;
            k--;
        }
    }
    // cout<<k<<endl;
    // Output

    if(!k){
        int oddCnt = 0;
        for(auto i: mpp){
            if((i.second)%2) oddCnt++;
        }

        if(oddCnt<=1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

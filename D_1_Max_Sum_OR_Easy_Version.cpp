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
#include<bitset>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int flipbits(int x) {
    int msb = 31 - __builtin_clz(x);  
    int mask = (1 << (msb + 1)) - 1;  
    return (~x) & mask;
}

void solve(){
    int l, r; cin>>l>>r;
    // l = 0 (given)
    // r < 2*10^5 (given)
    int n = r-l+1;

    vector<pair<int, int>> b;

    int ptr =r;
    while(ptr > 0){
        int nearestPowerOf2 = 1;
        while(nearestPowerOf2*2 <= ptr){
            nearestPowerOf2 *= 2;
        }
        // cout<<"Nearest Power of 2: "<<nearestPowerOf2<<endl;
        // cout<<"PtrEarly: "<<ptr<<endl;
        int last = ptr;

        while(ptr >= nearestPowerOf2){
            int value = ptr;
            int complimentValue = flipbits(value);
            auto myPair1 = make_pair(value, complimentValue);
            auto myPair2 = make_pair(complimentValue, value);  
            b.push_back(myPair1);
            b.push_back(myPair2);
            ptr--;
        }

        // cout<<"PtrAfter1: "<<ptr<<endl;
        ptr -= last - ptr ;
        // cout<<"PtrAfter2: "<<ptr<<endl;

        if(ptr==0) break;

    }

    if(ptr == 0){
        b.push_back(make_pair(0, 0));
    }

    sort(b.begin(), b.end());

    int len = b.size();
    ll SumbitOr = 0;

    for(auto i: b){
        SumbitOr += i.first | i.second;
    }

    // if(len!=n){
    //     // cout<<"len: "<<len<<" n: "<<n<<endl;
    // }
    cout<<SumbitOr<<endl;
    for(int i = 0; i<len; i++){
        cout<<b[i].second<<" ";
    }
    cout<<endl;

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

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

string toBinary(int n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve(){
    int a, b; cin>>a>>b;

    if(b==a){
        cout<<0<<endl;
        return;
    }

    string aBinary = toBinary(a);
    string bBinary = toBinary(b);
    // cout<<aBinary<<" "<<bBinary<<endl;
    // return;

    if(bBinary.length() > aBinary.length()){
        cout<<-1<<endl;
        return;
    }

    if(aBinary.length() > bBinary.length()){
        int diff = aBinary.length() - bBinary.length();
        bBinary = string(diff, '0') + bBinary;
    }

    int len = aBinary.length();
    vector<int> ans;

    for(int i = len-1; i>=0; i--){
        if(aBinary[i] != bBinary[i]){
            ans.push_back(1 << (len - 1 - i));
        }
    }

    cout<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

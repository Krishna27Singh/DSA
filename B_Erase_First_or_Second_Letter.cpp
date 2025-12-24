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

void f(string &s, set<string> &distinctString, unordered_set<string> &visited){
    //base case
    if(s.length()==0) return;
    if(s.length()==1){
        distinctString.insert(s);
        return;
    }
    if(s.length()==2){
        distinctString.insert(s);
        distinctString.insert(string(1, s[1]));
        distinctString.insert(string(1, s[0]));
        return;
    }

    if (visited.count(s)) return;
    visited.insert(s);

    string tempS = s;
    distinctString.insert(tempS);
    //case1
    f(tempS.erase(0,1), distinctString, visited);
    //case2
    tempS = s;
    f(tempS.erase(1,1), distinctString, visited);
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    
    unordered_set<char> visited;
    
    int cnt = 0;

    for(int i = 0; i<n; i++){
        if(!visited.count(s[i])) cnt += n-i;
        visited.insert(s[i]);
    }

    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

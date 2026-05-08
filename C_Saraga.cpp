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
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    string s; cin>>s;
    string t; cin>>t;

    vector<int> a(26, INF);
    vector<int> b(26, -INF);

    int n1 = s.size();
    int n2 = t.size();

    if(n1 > 1){
        for(int i = 1; i<n1; i++){
        a[s[i]-'a'] = min(a[s[i]-'a'], i);
    }
    }

    for(int i = 0; i<n2-1; i++){
        b[t[i]-'a'] = max(b[t[i]-'a'], i);
    }

    int len = INF;
    string ans = "";
    
    
    for(int i = 0; i<26; i++){
        if(a[i] == INF || b[i] == -INF) continue;
        if((a[i] + 1) + (n2 - b[i]) < len){
            // cout<<"i: "<<i<<" a[i]: "<<a[i]<<" b[i]: "<<b[i]<<endl;
            len = (a[i] + 1) + (n2 - b[i]);
            // take as as s from 0 to a[i] and t from b[i] to n2-1
            // cout<<s.substr(0, a[i])<<" "<<t.substr(b[i])<<endl;
            ans = s.substr(0, a[i]) + t.substr(b[i]);
        }
    }

    if(len == INF){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

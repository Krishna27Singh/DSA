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
    string t; cin>>t;
    int n = t.size();
    
    // string s should be greate than equal to n/2 + 1

    string s = "";
    for(int i = 0; i<n/2; i++) s += t[i];

    for(int i = n/2; i<n-1; i++){
        s += t[i];
        int sz = s.size();
        string suf = t.substr(sz);
        string sufs = s.substr(sz - (n - sz));
        int overlapping = 2*sz - n;
        string pref = s.substr(0, overlapping);
        string suff = s.substr(sz - overlapping);
        if(suf == sufs && pref == suff){
            cout<<"YES"<<endl;
            cout<<s<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    return;

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

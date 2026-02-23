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
score -> number of blocks in the final string
maximize the number of blocks


*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    int blocks = 0;
    bool flag = false;
    for(int i = 0; i<n; i++){
        char ch = s[i];
        int size = 0;
        while(s[i] == ch){
            i++;
            size++;
        }
        if(size >= 2) flag = true;
        i--;
        blocks++;
    }

    // cout<<blocks<<endl;
    if(s[0] == s[n-1]){
        cout<<blocks<<endl;
    }
    else{
        if(flag){
            cout<<blocks+1<<endl;
        }
        else cout<<blocks<<endl;
    }

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

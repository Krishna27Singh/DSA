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
    int n; cin>>n;

    string s = "";

    bool flag1 = true;
    bool flag2 = true;

    while(s.size() < n){

    if(flag1 && s.size() < n){
        cout<<"? "<<s+'1'<<endl;
        cout.flush();

        int x; cin>>x;

        if(x){
            s += '1';
        }
        else if(flag2 == false && s.size() == n-1){
            s += '0';
        }
        else{
            cout<<"? "<<s+'0'<<endl;
            cout.flush();

            cin>>x;

            if(x) s += '0';
            else flag1 = false;
        }
    }

    if(flag2 && s.size() < n){
        cout<<"? "<<'1'+s<<endl;
        cout.flush();

        int x; cin>>x;

        if(x){
            s = '1' + s;
        }
        else if(flag1 == false && s.size() == n-1){
            s = '0' + s;
        }
        else{
            cout<<"? "<<'0'+s<<endl;
            cout.flush();

            cin>>x;

            if(x) s = '0' + s;
            else flag2 = false;
        }
    }
}

    cout<<"! "<<s<<endl;
    cout.flush();

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

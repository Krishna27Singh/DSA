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

void solve(){
    int n, x; cin>>n>>x;

    if(n==1 && x==0){
        cout<<-1<<endl;
        return;
    }

    int setBits = 0;
    int temp = x;
    while(temp){
        setBits += temp & 1;
        temp >>= 1;
    }
    // cout<<"setbits: "<<setBits<<endl;
    if(n <= setBits){
        cout<<x<<endl;
        return;
    }

    int sum = x;
    if((n-setBits)%2==0){
        cout<<sum + (n-setBits)<<endl;
        return;
    }
    else{
        if(x>1) cout<<sum + n - setBits + 1<<endl;
        else cout<<n+3<<endl;
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

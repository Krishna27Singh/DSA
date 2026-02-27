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
a -> number of ones in the left half 
b -> number of ones in the right half
maximum a * b


*/

void solve(){
    ll n, m; cin>>n>>m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    ll ones = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]) ones++;
        }
    }
    ll target = ones/2;
    if(target == 0){
        cout << 0 <<endl;
        for(int i = 0; i < m; i++) cout << "R";
        for(int i = 0; i < n; i++) cout << "D";
        cout <<endl;
        return;
    }

    ll ans = target * (ones - target);
    // cout<<"Target: "<<target<<endl;

    ll targetRow, targetCol;
    for(int row = 0; row <n; row++){
        bool flag = false;
        for(int col = m-1; col>=0; col--){
            if(grid[row][col] == 1){
                target--;
                if(target == 0){
                    targetRow = row;
                    targetCol = col;
                    flag = true;
                    break;
                }
            }
            // cout<<"row: "<<row<<" col: "<<col<<" target: "<<target<<" curr: "<<grid[row][col]<<endl;
        }
        if(flag) break;
    }

    // cout<<ones<<" "<<target<<endl;
    // cout<<targetRow<<" "<<targetCol<<endl;
    cout<<ans<<endl;
    for(int i = 0; i<targetRow; i++) cout<<"D";
    for(int i = 0; i<targetCol; i++) cout<<"R";
    cout<<"D";
    for(int i = 0; i<m-targetCol; i++) cout<<"R";
    for(int i = 1; i<n-targetRow; i++) cout<<"D";
    cout<<endl;


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

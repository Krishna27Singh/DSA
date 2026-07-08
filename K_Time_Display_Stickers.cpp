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
    string s; cin>>s;

    unordered_map<int, int> mpp;
    for(int i = 0; i<n; i++) mpp[s[i]-'0']++;

    int cnt = 0;

    int h1 = 0;
    for(int h2 = 9; h2>=1; h2--){
        for(int m2 = 9; m2>=0; m2--){
            for(int m1 = 5; m1>=0; m1--){
                if(mpp[h1] > 0) mpp[h1]--;
                else continue;
                if(mpp[h2] > 0) mpp[h2]--;
                else {
                    mpp[h1]++;
                    continue;  
                }
                if(mpp[m1] > 0) mpp[m1]--;
                else {
                    mpp[h1]++;
                    mpp[h2]++;
                    continue;  
                }
                if(mpp[m2] > 0){
                    mpp[m2]--;
                    cnt++;
                }
                else{
                    mpp[h1]++;
                    mpp[h2]++;
                    mpp[m1]++;
                }
            }
        }
    }

    for(int h1 = 0, h2 = 0; h1<=1 && h2<=1; h1++, h2++){
        for(int m2 = 9; m2>=0; m2--){
            for(int m1 = 5; m1>=0; m1--){
                if(mpp[h1] > 0) mpp[h1]--;
                else continue;
                if(mpp[h2] > 0) mpp[h2]--;
                else {
                    mpp[h1]++;
                    continue;  
                }
                if(mpp[m1] > 0) mpp[m1]--;
                else {
                    mpp[h1]++;
                    mpp[h2]++;
                    continue;  
                }
                if(mpp[m2] > 0){
                    mpp[m2]--;
                    cnt++;
                }
                else{
                    mpp[h1]++;
                    mpp[h2]++;
                    mpp[m1]++;
                }
            }
        }
    }

    cout<<cnt<<endl;

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

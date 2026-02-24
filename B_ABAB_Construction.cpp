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
    int n; cin>>n;
    string x; cin>>x;
    string s = "";
    for(int i = 0; i<n; i++){
        if(i%2 == 0) s.push_back('a');
        else s.push_back('b');
    }

    int left = 0;
    int right = n-1;

    for(int i = 0; i<n; i++){
        char ch = x[i];
        if(ch == '?'){
            if(i+1 < n && x[i+1] != '?'){
                if(s[left] == s[right]) left++;
                else{
                    char req = x[i+1];
                    if(s[left] == req){
                        right--;
                    }
                    else left++;
                }
            }
            else{
                left++;
            }
        }
        else if(ch == s[left]){
            left++;
        }
        else if(ch == s[right]){
            right--;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

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

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
example tc

k = 4, n = 6

whwiff
fmowtn
rtwwni
uwftni
------
wtfwtf

iterate over divisors of n and check if the informativeness of the sting can be that divisor
suppose we are checking for divisor d
1, 1+d should be same
2, 2+d should be same
d, d+d should be same
we can keep track of elements by using an unordered map

freq[i] -> stores the frequency of all the elements at index i
*/

void solve(){
    int n, k; cin>>n>>k;
    vector<string> strips(k);
    for(int i = 0; i<k; i++){
        cin>>strips[i];
    }
    vector<unordered_map<char,int>> freq(n);
    for(int j = 0; j < k; j++){
        for(int i = 0; i < n; i++){
            freq[i][strips[j][i]]++;
        }
    }

    for(char c = 'a'; c<='z'; c++){
        bool flag = true;
        for(int i = 0; i<n; i++){
            if(freq[i].find(c) == freq[i].end()){
                flag = false;
                break;
            }
        }
        if(flag){
            string ans = "";
            for(int i= 0; i<n; i++) ans.push_back(c);
            cout<<ans<<endl;
            return;
        }
    }

    vector<int> divisors;
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0){
            divisors.pb(i);
            if(n/i != i) divisors.pb(n/i);
        }
    }
    sort(all(divisors));
    // reverse(all(divisors));
    int len = divisors.size();
    for(auto d : divisors){
                    string ans = "";
                    bool check = true;
                    for(int p = 0; p<d; p++){
                        bool ok = false;
                        for(char c = 'a'; c<='z'; c++){
                            bool flag = true;
                            for(int q = 0; q<n/d; q++){
                                if(freq[p+q*d].find(c) == freq[p+q*d].end()){
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag == true){
                                ok = true;
                                ans.push_back(c);
                                break;
                            }
                        }
                        if(ok == false){
                            check = false;
                            break;
                        }
                    }
                    if(check == false) continue;
                    string temp = ans;
                    for(int k = 1; k<n/d; k++) ans += temp;
                    cout<<ans<<endl;
                    return;
    }
    cout<<strips[0]<<endl;




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

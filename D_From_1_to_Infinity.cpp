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
                1234567891011121314151617181920

make a cut at k position
sum of digits uptill k ?


*/

void solve(){
    ll k; cin>>k;
    ll temp = k;
    int dig = 0;
    int rem;
    while(temp > 0){
        temp -= 9 * pow(10, dig);
        if(temp <= 0){
            temp += 9 * pow(10, dig);
            rem = temp;
            break;
        }
        dig++;
    }
    dig++;
    ll n = pow(10, dig-1) + rem/dig -1;
    // need to find sum of sum of digits uptill n
    cout<<"digit: "<<dig<<" remaining: "<<rem<<" n: "<<n<<endl;
    rem = rem%dig;
    // add sum to sum of rem digits from the starting of the number n + 1

    // what my dp will be storing ?
    // sum of digits of number num
    vector<int> dp(n+1, 0);

    ll ans = 0;
    for(int num = 1; num <= n; num++){
        // iterate on the digits of number num
        int temp = num;
        int sum = 0;
        while(temp){
            if(dp[temp] != 0){
                sum += dp[temp];
                break;
            }
            int digit = temp % 10;
            temp = temp /10;
            sum += digit;
        }
        dp[num] = sum;
        ans += sum;
    }

    int waste = dig - rem;
    temp = n+1;
    while(waste){
        temp = temp/10;
        waste--;
    }

    while(temp){
        int digit = temp%10;
        temp = temp/10;
        ans++;
    }

    cout<<ans<<endl;

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

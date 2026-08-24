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
it is the best if we remove the box from the smallest column
first calculate the answer without removing any box and then check if we can remove a box from the smallest column
for each column calculate how many boxes are there in the columns to the left which are in height greater than or equal to the height of the current column and then find the maximum possible answer

main problem -> calulating the total sum 
we need the minimum, 2nd minimum,, to the right side 
end configuration must be sorted 

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<ll> temp = a;
    sort(all(temp));

    ll initial = 0;
    for(int i = 0; i<n; i++) initial += i*a[i];

    ll finall = 0;
    for(int i = n; i>=1; i--){
        ll ch = n - (lower_bound(all(temp), i) - temp.begin());
        finall += n*ch - (ch*(ch+1))/2;
    }

    ll ans = abs(initial - finall);
    // cout<<"ans: "<<ans<<endl;

    // now calculating for each column how many boxes are there in the columns to the left which are in height greater than or equal to the height of the current column in O(nlogn) time complexity
    ll maxi = 0;
    for(int i = 0; i < n; i++){
        ll cnt = n - (lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin());
        ll gain = i - (n - cnt);
        if (gain > maxi) maxi = gain;
    }
    // for(auto i: left) cout<<i<<" ";
    // cout<<endl;

    cout<< ans + maxi <<endl;


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
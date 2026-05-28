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
only condition -> side should be parallel to coordinate axes
maximum possble area of rectangle
area = l * b
*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    vector<int> pairs;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i+1]) {
            pairs.push_back(a[i]);
            i++; 
        }
    }

    if(pairs.size() < 4) {
        cout << "NO\n";
        return;
    }

    int k = pairs.size();
    int A = pairs[0];
    int B = pairs[1];
    int C = pairs[k-2];
    int D = pairs[k-1];

    cout << "YES\n";
    cout << A << " " << B << " " << A << " " << D << " " << C << " " << B << " " << C << " " << D << "\n";

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

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
    int n, d, k; cin>>n>>d>>k;
    vector<pair<int, int>> lr(k);
    vector<int> start_cnt(n + 2, 0);
    vector<int> end_cnt(n + 2, 0);
    
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        start_cnt[l]++;
        end_cnt[r]++;
    }
    
    for(int i = 1; i <= n; i++){
        start_cnt[i] += start_cnt[i - 1];
        end_cnt[i] += end_cnt[i - 1];
    }
    
    int max_overlaps = -1;
    int min_overlaps = k + 1; 
    
    int brother_start = 1;
    int mother_start = 1;
    
    for(int i = 1; i <= n - d + 1; i++){
        int current_overlaps = start_cnt[i + d - 1] - end_cnt[i - 1];
        
        if(current_overlaps > max_overlaps){
            max_overlaps = current_overlaps;
            brother_start = i;
        }
        
        if(current_overlaps < min_overlaps){
            min_overlaps = current_overlaps;
            mother_start = i;
        }
    }
    
    cout << brother_start << " " << mother_start << "\n";

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

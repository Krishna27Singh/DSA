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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    //    0 1 0 1 1 0 0 1
    //  1 2 2 2 3

    int n; cin>>n;
    vector<int> b(n-2);
    for(int i = 0; i<n-2; i++) cin>>b[i];

    int len = b.size();
    for(int i = 0; i<len-2; i++){
        if(b[i]==1 && b[i+1]==0 && b[i+2]==1){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    // Output
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

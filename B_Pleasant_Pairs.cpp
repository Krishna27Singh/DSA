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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int maxi = 2*n-1;

    vector<pair<int, int> > aIdx;
    for(int i = 0; i<n; i++){
        auto myPair = make_pair(a[i], i+1);
        aIdx.push_back(myPair);
    }
    sort(aIdx.begin(), aIdx.end());

    int count = 0;
    for(int i = 0; i<n-1; i++){
        if(aIdx[i].first * aIdx[i+1].first > maxi) break;
        int currVal = aIdx[i].first;
        int currIdx = aIdx[i].second;

        for(int j = i+1; j<n; j++){
            int tempVal = aIdx[j].first;
            int tempIdx = aIdx[j].second;

            if(currVal*tempVal > maxi) break;

            if(currVal*tempVal == currIdx + tempIdx) count++;
        }
    }

    cout<<count<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    unordered_map<int, int> mpp;
    for(auto i: b) mpp[i]++;
    // for(auto i: mpp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    for(auto i: mpp){
        if(i.second % i.first){
            cout<<-1<<endl;
            return;
        }
    }

    vector<pair<int ,int>> valIdx;
    for(int i = 0; i<n; i++){
        valIdx.push_back({b[i], i});
    }
    sort(valIdx.begin(), valIdx.end());

    vector<int> ans(n, 0);

    int fill = 1;
    for(int i = 0; i<n;){
        int groups = mpp[valIdx[i].first] / valIdx[i].first;
        // cout<<"Groups: "<<groups<<endl;
        for(int g = 0; g<groups; g++){
            for(int j = 0; j<valIdx[i].first; j++){
                ans[valIdx[i + j].second] = fill;
            }
            i += valIdx[i].first;
            fill++;
        }

        
    }
    // Output
    for(int i = 0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

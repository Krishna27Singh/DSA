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
    long long n, k, x; cin>>n>>k>>x;
    vector<long long> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<pair<long long, bool> > gapsToFill_filled;

    sort(a.begin(), a.end());
    for(int i = 0; i<n-1; i++){
        if(a[i+1]-a[i] > x){
            auto myPair = make_pair(a[i+1]-a[i], false);
            gapsToFill_filled.push_back(myPair);
        }
    }

    // cout<<gapsToFill_filled.size()<<endl;
    // for(auto i: gapsToFill_filled) cout<<i.first<<" "<<i.second<<" "<<endl;
    sort(gapsToFill_filled.begin(), gapsToFill_filled.end());

    int it = gapsToFill_filled.size();
    for(int i = 0; i<it; i++){
        long long gap = gapsToFill_filled[i].first;
        long long people_required = gap/x;
        if(gap%x==0) people_required--;

        if(k>=people_required){
            k -= people_required;
            // cout<<"exe"<<endl;
            gapsToFill_filled[i].second = true;
        }
    }

    // for(auto i: gapsToFill_filled) cout<<i.first<<" "<<i.second<<" "<<endl;

    int count = 0;
    for(int i = 0; i<it; i++){
        if(gapsToFill_filled[i].second == false){
            count = it - i;
            break;
        }
    }

    cout<<count+1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

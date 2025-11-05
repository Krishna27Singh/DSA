#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<pair<int, int> > freqBuilding;
    for(int i = 0; i<n; i++){
        auto freq_building = make_pair(a[i], i+1);
        freqBuilding.push_back(freq_building);
    }
    sort(freqBuilding.begin(), freqBuilding.end());
    reverse(freqBuilding.begin(), freqBuilding.end());


    vector<pair<int,int> > position;
    long long ans = 0;

    int count = 0;
    count = 1;
    for(int i = 0; i<freqBuilding.size(); i++){
        if(i%2==0){
            auto newPair = make_pair(freqBuilding[i].second - 1, count);
            position.push_back(newPair);
            ans += freqBuilding[i].first * 2LL * abs(count);
        }
        else{
            auto newPair = make_pair(freqBuilding[i].second - 1, -count);
            position.push_back(newPair);
            ans += freqBuilding[i].first * 2LL * abs(count);
        }

        if(i%2 != 0) count++;
    }

    sort(position.begin(), position.end());
    cout<<ans<<endl;
    cout<<0<<" ";
    for(auto i: position) cout<<i.second<<" ";
    cout<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

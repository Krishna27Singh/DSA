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
    int n, qSize; cin>>n>>qSize;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> q(qSize);
    for(int i = 0; i<qSize; i++) cin>>q[i];

    vector<pair<int, int> > qSorted;
    for(int i = 0; i<qSize; i++){
        auto myPair = make_pair(q[i], i);
        qSorted.push_back(myPair);
    }
    sort(qSorted.begin(), qSorted.end());

    vector<pair<long long, long long> > height_maxSteps;
    long long height = 0;
    int maxSteps = a[0];
    height += a[0];
    auto myPair = make_pair(height, maxSteps);
    height_maxSteps.push_back(myPair);
    for(int i = 1; i<n; i++){
        maxSteps = max(maxSteps, a[i]);
        height += a[i];
        auto myPair = make_pair(height, maxSteps);
        height_maxSteps.push_back(myPair);
    }

    vector<pair<long long, long long> > ans;
    int i = 0; int j = 0;
    while(j<qSize){
        if(qSorted[j].first >= height_maxSteps[i].second){
            if(i<n-1) i++;
            else break;
        }
        else{
            if(i==0){
                auto myPair = make_pair(qSorted[j].second, 0);
                ans.push_back(myPair);
            }
            else{
                auto myPair = make_pair(qSorted[j].second, height_maxSteps[i-1].first);
                ans.push_back(myPair);
            }
            j++;
        }
    }

    int rem =  qSize - ans.size();
    for(int i = 0; i<rem; i++) {
        auto myPair = make_pair(qSorted[j+i].second, height);
        ans.push_back(myPair);
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans) cout<<i.second<<" ";
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

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
    int n, m; cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i<m; i++) cin>>a[i];
    sort(a.begin(), a.end());

    vector<int> originalUninfected;
    for(int i = 0; i<m-1; i++) originalUninfected.push_back(a[i+1]-a[i]-1);
    originalUninfected.push_back(n-1-a[m-1] + a[0]);

    sort(originalUninfected.begin(), originalUninfected.end());
    // for(auto i: originalUninfected) cout<<i<<" ";
    // cout<<endl;

    vector<int> finalUninfected = originalUninfected;

    for(int i = finalUninfected.size()-1; i>=0; i--){
        if(finalUninfected[i]==0) break;
        if(finalUninfected[i]>1) finalUninfected[i]--;
        for(int j = i-1; j>=0; j--){
            if(finalUninfected[j]==0){
                // cout<<"triggered1"<<endl;
                continue;
            }
            if(finalUninfected[j]>=4){
                // cout<<"triggered2"<<endl;
                finalUninfected[j] -= 4;
            }
            else if(finalUninfected[j]==3){
                // cout<<"triggered3"<<endl;
                finalUninfected[j]-=3;
            }
            else if(finalUninfected[j]==2){
                // cout<<"triggered3"<<endl;
                finalUninfected[j]-=2;
            }
            else if(finalUninfected[j]==1){
                // cout<<"triggered3"<<endl;
                finalUninfected[j]-=1;
            }
        }
    //     for(auto i: finalUninfected) cout<<i<<" ";
    // cout<<endl;
    }

    // for(auto i: finalUninfected) cout<<i<<" ";
    // cout<<endl;

    int totalUninfected = 0;
    for(auto i: finalUninfected) totalUninfected += i;
    // cout<<"total"<<totalUninfected<<endl;

    cout<<n-totalUninfected<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

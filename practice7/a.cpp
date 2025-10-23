#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        vector<int> b(n);
        for(int i = 0; i<n; i++) cin>>b[i];
        vector<int> c(n);
        for(int i = 0; i<n; i++) cin>>c[i];

        vector<pair<int, int>> activity1max;
        for(int i = 0; i<n; i++){
            activity1max.push_back({a[i], i});
        }
        vector<pair<int, int>> activity2max;
        for(int i = 0; i<n; i++){
            activity2max.push_back({b[i], i});
        }
        vector<pair<int, int>> activity3max;
        for(int i = 0; i<n; i++){
            activity3max.push_back({c[i], i});
        }

        sort(activity1max.begin(), activity1max.end(), greater<pair<int,int>>());
        sort(activity2max.begin(), activity2max.end(), greater<pair<int,int>>());
        sort(activity3max.begin(), activity3max.end(), greater<pair<int,int>>());

        int ans = 0;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    if(activity1max[i].second != activity2max[j].second && activity2max[j].second != activity3max[k].second && activity1max[i].second != activity3max[k].second){
                        ans = max(ans, activity1max[i].first + activity2max[j].first + activity3max[k].first);
                }
            }
        }


        cout<<ans<<endl;
    }

    return 0;
}
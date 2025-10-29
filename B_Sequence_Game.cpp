#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int m; cin>>m;
        vector<int> a(m);
        for(int i=0;i<m;i++) cin>>a[i];

        vector<int> ans;
        ans.push_back(a[0]);

        for(int i = 1; i<m; i++){
            if(a[i]>=a[i-1]) ans.push_back(a[i]);
            else{
                ans.push_back(a[i]);
                ans.push_back(a[i]);
            }
        }

        cout<<ans.size()<<endl;
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
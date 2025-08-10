#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> height(n);
        for(int i = 0; i<n; i++) cin>>height[i];

        set<int> s(height.begin(), height.end());
        vector<int> h(s.begin(), s.end());
        int water_level = 0;
        sort(h.begin(), h.end());

        bool is_possible = true;
        int seconds = 1;
        n = h.size();

        int value = height[k-1];
        int it = 0;
        for(int i = 0; i<n; i++){
            if(h[i]==value){
                it = i;
                break;
            }
        }
        
        for(int i = it; i<n-1; i++){
            int second = h[i+1]-h[i];
            seconds += second;
            water_level += second;
            cout<<water_level<<" "<<h[i]<<endl;
            if(water_level > h[i]) is_possible = false; 
            
        }

        if(is_possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
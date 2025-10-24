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

        for(int i = 0; i<n; i++){
            a[i] = abs(a[i]);
        }
        
        
        sort(a.begin(), a.end());
        
        cout<<a[0]<<endl;
    }
    
    return 0;
}
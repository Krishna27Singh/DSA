#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, x; cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        int maximum = a[0] + x + x;
        int minimum = a[0] - x - x;

        int cnt = 0;
        for(int i = 1; i<n; i++){
            if(a[i]>maximum || a[i]<minimum){
                cnt++;
                maximum = a[i]+x+x;
                minimum = a[i]-x-x;
            }
        }

        cout<<cnt<<endl;
        
    }

    return 0;
}
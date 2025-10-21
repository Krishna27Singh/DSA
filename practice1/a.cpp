#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, x; cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        int ans = INT_MIN;

        for(int i = 0; i<n-1; i++){
            ans = max(ans, a[i+1]-a[i]);
        }

        ans = max(ans, a[0]);
        ans = max(ans, 2*(x - a[n-1]));

        cout<<ans<<endl;
    }

    return 0;
}
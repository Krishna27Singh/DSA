#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, j, k; cin>>n>>j>>k;
        vector<int> a(n); for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> dup(a.begin(), a.end());
        sort(dup.begin(), dup.end());
        if(k==1) {
            if(dup[n-1]==a[j-1]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        vector<int> b(n);
        for(int i = 0; i<n; i++) cin>>b[i];

        bool check = true;
        if(a[n-1]!=b[n-1]){
            cout<<"NO"<<endl;
            continue;
        }   
        for(int i = n-2; i>=0; i--){
            if((a[i]==b[i]) || ((a[i]^a[i+1])==b[i]) || ((a[i]^b[i+1])==b[i])) continue;
            else {
                check = false;
                break;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
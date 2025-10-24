#include<iostream>
using namespace std;   

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        int check = false;

        for(int i = 0; i<n-2; i++){
            if(a[i]!=a[i+2]){
                check = true;
                break;
            }
        }

        if(check) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}
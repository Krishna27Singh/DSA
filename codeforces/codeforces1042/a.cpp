#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        vector<int> b(n);
        for(int i = 0; i<n; i++) cin>>b[i];


        int neg = 1;
        int pos = 1;

        for(int i = 0; i<n; i++){
            if(a[i]>b[i]){
                neg += a[i]-b[i];
            }
            if(b[i]>a[i]){
                pos = b[i]-a[i];
            }
        }

        if(neg<=pos) cout<<neg<<endl;
        else cout<<neg<<endl;
    }

    return 0;
}
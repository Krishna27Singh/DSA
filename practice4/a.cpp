#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        bool check = false;

        for(int i = 0; i<n; i++){
            int hamming = abs(a[i]-(i+1));
            if(hamming>1) check = true;
        }

        if (check) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}
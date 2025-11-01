#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        string s,t; cin>>s>>t;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
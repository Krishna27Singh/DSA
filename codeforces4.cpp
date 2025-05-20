#include<iostream>
using namespace std;
using ll = long long;

int main(){

    ll tc; cin>>tc;
    while(tc--){
        ll n,m,p,q; cin>>n; cin>>m; cin>>p; cin>>q;
        if(n%p==0){
            if(q*n/p==m) cout<<"YES";
            else cout<<"NO";
        }
        else cout<<"YES";
    }
    
}
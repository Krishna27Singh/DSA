#include<iostream>
using namespace std;
using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

ll ans(ll n){
    ll cnt = 0;
    while(n>1){
        n=(n+1)/2;
        cnt++;
    }
    return cnt;
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        ll n,m,a,b; cin>>n>>m>>a>>b;
        if((n+1-a)<a) a = n+1-a;
        if((m+1-b)<b) b = m+1-b;

        cout<<min(1+ans(n)+ans(b), 1+ans(a)+ans(m))<<endl;

    }
    return 0;
}
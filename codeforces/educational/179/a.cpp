#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        long long x; cin>>x;
        int ans = 1;

        while(x){
            x = x/2;
            ans += 2;
        }

        cout<<ans<<endl;
    }
    return 0;
}
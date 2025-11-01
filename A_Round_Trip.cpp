#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        long long Ro, X, D, n; cin>>Ro>>X>>D>>n;
        string rounds; cin>>rounds;

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(rounds[i]=='1'){
                ans++;
                if(Ro >= X){
                    Ro -= D;
                    if(Ro < 0) Ro = 0;
                }
            }
            else{
                if(Ro<X) ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
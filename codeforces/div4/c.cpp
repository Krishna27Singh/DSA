#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        vector<int> req(n);
        vector<int> cp(n);
        for(int i = 0; i<n; i++){
            cin>>req[i];
            cin>>cp[i];
        }

        int curr = 0;
        
        int state = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int dest = req[i];
            if(state == cp[i] && (dest-curr)%2==0){
                ans += dest-curr;
            }
            else if(state == cp[i] && (dest-curr)%2!=0){
                ans += dest-curr-1;
            }
            else if(state != cp[i] && (dest-curr)%2!=0){
                ans += dest-curr;
            }
            else if(state != cp[i] && (dest-curr)%2==0){
                ans += dest-curr-1;
            }

            state = cp[i];
            curr = req[i];
        }

        if(req[n-1]!=m){
            ans += req[n-1]-1;
        }

        cout<<ans<<endl;
    }

    return 0;
}
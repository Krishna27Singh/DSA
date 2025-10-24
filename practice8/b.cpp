#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, c; cin>>n>>c;
        string s; cin>>s;
        
        s += s;

        int last_green = -1;
        int ans = INT_MIN;

        for(int i = 2*n-1; i>=0; i--){
            if(s[i]=='g') last_green = i;
            if(s[i]==c && last_green != -1 && last_green < n){
                ans = max(ans, last_green - i);
            }
        }

        cout<<ans<<endl;


    }

    return 0;
}
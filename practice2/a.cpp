#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        string s; cin>>s;

        vector<int> blocked;
        blocked.push_back(-1);

        for(int i = 0; i<n; i++){
            if(s[i]=='#'){
                blocked.push_back(i);
            }
        }

        blocked.push_back(n);

        int ans = 0;
        
        bool check = false;
        for(int i = 0; i<blocked.size()-1; i++){
            int len = blocked[i+1] - blocked[i]-1;
            if(len>2){
                check = true;
                break;
            }
            ans += len;
        }

        if(check) cout<<2<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
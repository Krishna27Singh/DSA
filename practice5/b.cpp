#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        string x, s; cin>>x>>s;
        bool check = false;
        int cnt = 0;
        
        while(x.size()<=s.size()){
            
            if(x.find(s) != string::npos){
                check = true;
                break;
            }
            else{
                x.append(x);
                cnt++;
            }
        }
        
        if(x.find(s) != string::npos){
                check = true;
                break;
            }
        
        if(check) cout<<cnt<<endl;
        else cout<<"-1"<<endl;
    }
    
    return 0;
    
}
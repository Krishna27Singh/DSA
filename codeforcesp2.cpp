#include<iostream>
using namespace std;

int main(){
    
    int tc; cin>>tc;
    while(tc--){
        int x, y, a; cin>>x>>y>>a;
        
        int digged = 0;
        int jumps = (a/(x+y));
        digged = digged+ jumps*(x+y);

        if(digged+x>a) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}
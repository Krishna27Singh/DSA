#include<iostream>
#include<vector>
using namespace std;   

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        if(n%3==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }

    return 0;
}
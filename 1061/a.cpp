#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>   

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;

        if(n%2==0){
            cout<<(n/2)-1<<endl;
        }
        else{
            cout<<n/2<<endl;
        }
    }

    return 0;
}
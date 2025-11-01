#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int a, b, c; cin>>a>>b>>c;

        if(a>b){
            cout<<"First"<<endl;
        }
        else if(b>a){
            cout<<"Second"<<endl;
        }
        else{
            if(c%2==0){
                cout<<"Second"<<endl;
            }
            else{
                cout<<"First"<<endl;
            }
        }
    }


    return 0;
}
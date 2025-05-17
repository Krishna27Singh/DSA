#include<iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    for(int z = 0; z<t; z++){
        int n;
        cin>>n;
        cout<<"digit"<<endl;
        cout.flush();
        int res;
        cin>>res;
        if(res){
            cout<<"add -9"<<endl;
            cout.flush();
            int res;
            cin>>res;
            if(res){
                cout<<"add 4"<<endl;
                cout.flush();
                int res;
                cin>>res;
                if(res){
                    cout<<"!"<<endl;
                }
            }
            else{
                cout<<"add 1"<<endl;
                cout.flush();
                int res;
                cin>>res;
                if(res){
                    cout<<"mul 10"<<endl;
                    cout.flush();
                    int res;
                    cin>>res;
                    if(res){
                        cout<<"!"<<endl;
                    }
                }
            }
        }
    }

    return 0;
}
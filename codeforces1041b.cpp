#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, x; cin>>n>>x;
        string s; cin>>s;
        x--;

        int left=-1, right=-1;
        for(int i = x-1; i<n; i++){
            if(s[i]=='#'){
                right = i+1;
                break;
            }
        }
        for(int i = x+1; i>=0; i--){
            if(s[i]=='#'){
                left = i+1;
                break;
            }
        }

        if(x==1 || x==n) {
            cout << "1"<<endl;
            continue;
        }
        if(left==-1 || right==-1){
            cout<<"1"<<endl;
            continue;
        }
        cout<<max(min(x+1, n-right+2), min(left+1, n-x))<<endl;
    }

    return 0;
}
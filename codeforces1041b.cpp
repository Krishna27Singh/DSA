#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, x; cin>>n>>x;
        string s; cin>>s;
        x--;

        int left=-1, right=-1;
        for(int i = x+1; i<n; i++){
            if(s[i]=='#'){
                right = i;
                break;
            }
        }
        for(int i = x-1; i>=0; i--){
            if(s[i]=='#'){
                left = i;
                break;
            }
        }

        if(x==1 || x==n) {
            cout << "1"<<endl;
            continue;
        }
        if(left==-1 && right==-1){
            cout<<"1"<<endl;
            continue;
        }
        cout<<max(min(x+1, n-right+1), min(left+2, n-x))<<endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        vector<int> w(m);
        vector<int> l(m);
        vector<int> h(m);
        for(int i = 0; i<m; i++){
            cin>>w[i];
            cin>>l[i];
            cin>>h[i];
        }
        vector<int> f(10);
        f[0]=1;
        f[1]=2;
        f[2]=3;
        f[3]=5;
        f[4]=8;
        f[5]=13;
        f[6]=21;
        f[7]=34;
        f[8]=55;
        f[9]=89;

        for(int i = 0; i<m; i++){
            if(w[i]>=f[n-1] && l[i]>=f[n-1] && h[i]>=f[n-1]){
                if((h[i]-f[n-1]>=f[n-2]) || (w[i]-f[n-1]>=f[n-2]) || (l[i]-f[n-1]>=f[n-2])){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0;
            }
        }

        cout<<endl;

    }
    return 0;
}
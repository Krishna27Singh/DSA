#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        string s; cin>>s;

        int ones = 0;
        int count_ones = 0;
        for(auto i: s) if(i=='1') ones++;
        
        if(!ones){
            cout<<n<<endl;
            continue;
        }

        for(auto i: s){
            if(i=='1') count_ones += ones-1;
            else count_ones += ones+1;
        }
        cout<<count_ones<<endl;
    }

    return 0;
}
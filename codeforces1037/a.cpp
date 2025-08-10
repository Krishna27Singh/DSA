#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int x; cin>>x;

        string str = to_string(x);
        int answer = INT_MAX;
        int n = str.size();
        for(int i = 0; i<n; i++){                                         
            if(int(str[i])-48 <answer) answer = int(str[i])-48;                
        }
        
        cout<<answer<<endl;

    }

    return 0;
}
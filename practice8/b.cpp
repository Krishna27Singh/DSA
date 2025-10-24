#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, c; cin>>n>>c;
        string s; cin>>s;
        int maxi = INT_MIN;
        cout<<s;

        for(int i = 0; i<n; i++){
            if(s[i]==c){
                int count = 0;
                int found = false;
                for(int j = i+1; j<n; j++){
                    if(s[j]=='g'){
                        cout<<s[j]<<" ";
                        found = true;
                        break;
                    }
                    count++;
                }
                if(found){
                    maxi = max(maxi, count);
                }
                else{
                    for(int j = 0; j<i; j++){
                        if(s[j]=='g'){
                            found = true;
                            break;
                        }
                        count++;
                    }

                    if(found){
                        maxi = max(maxi, count);
                        continue;
                    }
                }
            }
        }

    }

    return 0;
}
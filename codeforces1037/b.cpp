#include<iostream>
#include<vector>
using namespace std;

int calculateHikes(int count, int k){
    int hikes = 0;
    if(count<k+1){
        if(count==k){
            hikes += 1;
        }
        return hikes;
    }
    hikes += count/(k+1);
    if(count%(hikes*(k+1))==k) hikes++;

    return hikes;
}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        int hikes = 0;
        int x = 0;
        int y = 0;
        if(a[0]!=0){
            int i = 0;
            for(; i<n; i++){
                if(a[i]==0){
                    x=i;
                    y=i;
                    break;
                }
            }
            if(i==n){
                cout<<"0"<<endl;
                
                continue;
            }
        }
        while(y<n && x<n){
            int count = 0;
            int i = x;
            for(; i<n; i++){
                if(a[i]==1){
                    y = i;
                    break;
                }
                count++;
            }
            if(i==n){
                hikes += calculateHikes(n-x, k);
                break;
            }
            
            hikes += calculateHikes(count, k);

            int j = y;
            for(; j<n; j++){
                if(a[j]==0){
                    y = j;
                    break;
                }
            }
            if(j==n) break;

            

            x = y;
        }

        cout<<hikes<<endl;
    }

    return 0;
}
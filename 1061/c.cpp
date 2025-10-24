#include<iostream>
using namespace std;        
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>


int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> freq(n+1, 0);
        for(int i = 0; i<n; i++){
            int x; cin>>x;
            freq[x]++;
        }

        for(int i = 1; i<=n; i++) freq[i] += freq[i-1];

        for(int g = n; g>=1; g--){
            int pos = freq[min(n, 4 * g -1)];
            pos -= freq[g]-freq[g-1];
            if(2*g<=n) pos -= freq[2*g]-freq[2*g-1];
            if(3*g<=n) pos -= freq[3*g]-freq[3*g-1];

            if(pos<=k){
                cout<<g<<endl;
                break;
            }
        }

        
    }

    return 0;
}
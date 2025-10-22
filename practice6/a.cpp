#include<iostream>
using namespace std;
#include<vector>   
#include<unordered_map> 

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        bool check = false;

        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                unordered_map<int, int> freq;
                for(int x = i; x<=j; x++){
                    freq[a[x]]++;
                }
                int max_freq = 0;
                for(auto it : freq){
                    if(it.second > max_freq){
                        max_freq = it.second;
                    }
                }
                if(k>=max_freq){
                    check = true;
                    break;
                }
            }
        }

        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
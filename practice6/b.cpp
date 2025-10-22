#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        string s; cin>>s;

        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for(auto charr : s){
            mpp2[charr]++;
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            int a = mpp1.size();
            int b = mpp2.size();
            ans = max(ans, a+b);

            mpp1[s[i]]++;
            mpp2[s[i]]--;
        }

        cout<<ans<<endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        long long n, k, b, s; cin>>n>>k>>b>>s;
        vector<long long> ans;

        long long last_element = 1LL*((k*b) + (k-1));
        if(last_element>s){
            last_element = s-1;
        }
        long long remaining = 1LL*(s - last_element);
        
        long long all_element, second_last;
        if(n-1>0){
            all_element = 1LL*(remaining / (n-1) + 1);
         second_last  = 1LL*(s - last_element - (all_element * (n-2)));
        }
        if(second_last<0) second_last = 0;

        for(int i = 0; i<n-2; i++){
            ans.push_back(all_element);
        }
        if(n>=2) ans.push_back(second_last);
        ans.push_back(last_element);

        long long beauty = 0;
        long long sum = 0;
        for(auto i: ans){
            beauty += 1LL*(i / k);
            sum += 1LL*(i);
        }
        // if(beauty!=b || sum!=s){
        //     cout<<-1<<endl;
        //     continue;
        // }

        for(auto i: ans) cout<<i<<" ";
        cout<<endl;

        
    }

    return 0;
}
#include<iostream>
using namespace std;

int solve(int n, int t){
    if(t == 1) return n;
    vector<int> facts;
    for(int i = 2; i<=t; i++){
        if(t%i == 0) facts.push_back(i);
    }
    int ans = 0;
    int len = facts.size();
    for(auto i: facts) cout<<i<<" ";
    for(int i = len-1; i>=0; i--){
        ans += facts[i]*(pow(10, len-i-1));
    }
    if(ans < n){
        if(ans/10) ans += pow(10, 2);
        else ans += pow(10, 1);
    }
    if(ans < n) ans += pow(10, 2);
    return ans;
}

int main(){
    int n, t; cin>>n>>t;
    cout<<solve(n, t)<<"\n";

    return 0;
}
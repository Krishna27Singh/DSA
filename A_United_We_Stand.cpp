#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);   
        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> b;
        vector<int> c;
        sort(a.begin(), a.end());

        unordered_map<int, int> freq;
        for(auto i: a) freq[i]++;

        if(a[0]==a[n-1]){
            cout<<-1<<endl;
            continue;
        }

        int cnt = freq[a[0]];
        for(int i = 0; i<cnt; i++) b.push_back(a[0]);
        for(int i = cnt; i<n; i++){
            c.push_back(a[i]);
        }

        cout<<b.size()<<" "<<c.size()<<endl;
        for(auto i: b) cout<<i<<" ";
        cout<<endl;
        for(auto i: c) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

bool customSort(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;  
    return a.first > b.first;        
}


int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> health = a;
        for(int i = 0; i<n; i++){
            if(health[i]%k==0){
                health[i] = k;
                continue;
            }
            health[i] = health[i]%k;
        }

        vector<pair<int,int>> pairs;
        for(int i  = 0; i<n; i++){
            pairs.push_back({health[i], i+1});
        }

        sort(pairs.begin(), pairs.end(), customSort);

        for(int i = 0; i<n; i++){
            cout<<pairs[i].second<<" ";
        }
        cout<<endl;
    }

    return 0;
}
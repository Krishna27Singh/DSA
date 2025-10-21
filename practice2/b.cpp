#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, p; cin>>n>>p;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        vector<int> b(n);
        for(int i = 0; i<n; i++) cin>>b[i];

        int ans = 0;

        if(n==1){
            cout<<p<<endl;
            continue;
        }

        ans += p; n--;

        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({b[i], a[i]});
        }

        sort(pairs.begin(), pairs.end());

        for(int i = 0; i<n; i++){
            cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
        }

        for(auto duo : pairs){
            int cost = duo.first;
            int people = duo.second;

            if(cost>p) break;

            if(people>n){
                ans += cost * (people-n);
                break;
            }

            ans += cost*people;
            n -= people;
        }

        if(n>0){
            ans += p*n;
        }

        cout<<ans<<endl;
    }

    return 0;
}
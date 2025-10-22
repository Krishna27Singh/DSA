#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k, q; cin>>n>>k>>q;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> bad_weather;
        bad_weather.push_back(-1);

        for(int i = 0; i<n; i++){
            if(a[i]>q) bad_weather.push_back(i);
        }

        bad_weather.push_back(n);
        int ans = 0;

        for(int i = 0; i<bad_weather.size(); i++){
            int len = bad_weather[i+1]-bad_weather[i]-1;

            int cnt = len/k;
            ans += cnt;

        }

        cout<<ans<<endl;
    }

    return 0;
}
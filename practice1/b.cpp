#include<iostream>
using namespace std;    

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> primef;
        for(int i = 2; i<k/2; i++){
            if(k%i==0){
                primef.push_back(i);
            }
        }

        int ans = 0;
        bool executed = false;
        for(int i = 0; i<primef.size(); i++){
            bool executed = true;
            int value = primef[i];
            int diff = INT_MAX;
            for(int i = 0; i<n; i++){
                if(a[i]>k) continue;
                diff = min(diff, k-a[i]);
            }
            ans += diff;
        }

        int answer = INT_MAX;
        for(int i = 0; i<n; i++){
            if(a[i]>k) continue;
            answer = min(answer, k-a[i]);
        }

        if(executed){
            cout<<ans<<endl;
        }
        else{
            cout<<answer<<endl;
        }
    }

    return 0;
}
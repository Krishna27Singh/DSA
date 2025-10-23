#include<iostream>
using namespace std;
#include<vector>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n-1);
        for(int i = 0; i<n-1; i++) cin>>a[i];

        int sum = 0;
        for(int i = 0; i<n-1; i++) sum += a[i];

        cout<<-sum<<endl;
    }

    return 0;
}
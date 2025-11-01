#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void solve(){
    int n ; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int evens = 0; int odds = 0;
    for(auto i: a){
        if(i%2==0) evens++;
        else odds++;
    }

    if(odds%2==0){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int tc; cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}
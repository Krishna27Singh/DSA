#include<iostream>
#include<algorithm>
using namespace std;

void solve(int idx, int n, int &ans, vector<int> &a, vector<int> &b){
    if(idx==n){
        if(is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())){
            ans++;
        }
        return;
    }

    solve(idx+1, n, ans, a, b);

    swap(a[idx], b[idx]);
    solve(idx+1, n, ans, a, b);

}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];

        int ans = 0;

        solve(0, n, ans, a, b);

        cout<<ans<<endl;
    }

    return 0;
}
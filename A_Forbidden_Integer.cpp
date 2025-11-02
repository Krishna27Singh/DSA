#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    int n, k, x; cin>>n>>k>>x;
    if(x!=1 && k>=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i = 0; i<n; i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    
    if(k==2){
        if(n%2==0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i = 0; i<n/2; i++) cout<<2<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;

        return;
    }

    if(n%2!=0 && k>=3){
        n--; int it = n/2 - 1;
        cout<<"YES"<<endl;
        cout<<it+1<<endl;
        for(int i = 0; i<it; i++) cout<<2<<" ";
        cout<<3<<" ";
        return;
    }
    else if(n%2==0 && k>=2){
        int it = n/2;
        cout<<"YES"<<endl;
        cout<<it<<endl;
        for(int i = 0; i<it; i++) cout<<2<<" ";
        return;
    }

    cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

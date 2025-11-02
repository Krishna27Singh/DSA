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
    int x, k; cin>>x>>k;
    // cout<<x<<endl;
    // for(int i = 0; i<x; i++) cout<<1<<" ";
    // cout<<endl;
    // return;
    if(x<k){
        cout<<1<<endl;
        cout<<x<<endl;
        return;
    }

    if(k%2==0){
        if(x%2==0){
            if(x%k==0){
                cout<<2<<endl;
                cout<<x-1<<" "<<1<<endl;
            }
            else{
                cout<<1<<endl;
                cout<<x<<endl;
            }
        }
        else{

            cout<<1<<endl;
            cout<<x<<endl;
        }
        return;
    }
    else{
        if(x%2!=0){
            if(x%k!=0){
                cout<<1<<endl;
                cout<<x<<endl;
            }
            else{
                cout<<2<<endl;
                cout<<x-1<<" "<<1<<endl;
            }
        }
        else{
            if(x%k==0){
                cout<<2<<endl;
                cout<<x-1<<" "<<1<<endl;
            }
            else{
                cout<<1<<endl;
                cout<<x<<endl;
            }
        }
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

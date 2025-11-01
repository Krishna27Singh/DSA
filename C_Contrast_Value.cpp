#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include<utility>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    long long orgn; cin>>orgn;
    vector<long long> orga(orgn);
    for(int i = 0; i<orgn; i++) cin>>orga[i];

    vector<long long> a;
    for(int i = 0; i<orgn-1; i++){
        if(orga[i]!=orga[i+1]) a.push_back(orga[i]);
    }
    a.push_back(orga[orgn-1]);

    long long n = a.size();

    long long ans = 0; 
    ans += orgn - n;

    long long count = 1;
    for(int i = 0; i<n-1; i++){
        if(a[i]>a[i+1]){
            if(count>2){
                ans += count-2;
                count = 1;
            }
            else count = 1;
        }
        else{
            count++;
            if(i+1 == n-1 && count>2){
                ans += count-2;
            }
        }
    }

    count = 1;
    for(int i = 0; i<n-1; i++){
        if(a[i]<a[i+1]){
            if(count>2){
                ans += count-2;
                count = 1;
            }
            else count = 1;
        }
        else{
            count++;
            if(i+1 == n-1 && count>2){
                ans += count-2;
            }
        }
    }

    cout<<orgn - ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

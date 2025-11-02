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
#include<unordered_map>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    unordered_map<int, int> freq;
    for(auto i: a) freq[i]++;

    int ans = 0;
    sort(a.begin(), a.end());

    n = a.size();
    

    int count = freq[a[0]];
    for(int i = 0; i<n-1; i++){
        if(a[i+1]==a[i]) continue;
        if(a[i+1] != a[i] + 1){
            ans += count;
            count = freq[a[i+1]];
        }
        
        if(a[i+1] == a[i]+1 && freq[a[i+1]] != freq[a[i]]){
            if(freq[a[i+1]]>freq[a[i]]){
                count += freq[a[i+1]] - freq[a[i]];
            }
            else{
                ans += freq[a[i]] - freq[a[i+1]];
                count = freq[a[i+1]];
            }
        }
        
    }

    ans += count;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

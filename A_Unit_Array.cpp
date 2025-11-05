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
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int neg = 0;
    int pos = 0;
    
    for(auto i: a){
        if(i==-1) neg++;
        else pos++;
    }

    int ops = 0;
    if(neg>pos){
        if((neg-pos)%2 == 0){
            ops += (neg-pos)/2;
            neg -= (neg-pos)/2;
        }
        else{
            ops += (neg-pos)/2 + 1;
            neg -= (neg-pos)/2 + 1;
        }
    }

    if(neg%2!=0) ops++;

    cout<<ops<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

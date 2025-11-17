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
    int a,b,c,d; cin>>a>>b>>c>>d;

    if(d<b){
        cout<<-1<<endl;
        return;
    }

    int height = d-b;
    a += height;
    b += height;

    if(c>a){
        cout<<-1<<endl;
        return;
    }

    cout<<height + a-c<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    int MEX, XOR; cin>>MEX>>XOR;


    int currXor;
    int rem = (MEX-1)%4;
    if(rem == 0) currXor = MEX-1;
    else if(rem == 1) currXor = 1;
    else if(rem == 2) currXor = MEX;
    else if(rem == 3) currXor = 0;

    if(currXor == XOR) cout<<MEX<<endl;
    else{
        if((currXor ^ XOR) == MEX) cout<<MEX+2<<endl;
        else cout<<MEX+1<<endl;
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

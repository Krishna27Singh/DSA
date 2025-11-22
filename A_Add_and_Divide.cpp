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
    int a, b; cin>>a>>b;
    

    int ops = 0;
    int currMiniOps = 0;
    int i = 0;
    if(b==1) {
        b++;
        currMiniOps++;
        i++;
    }
    int tempa = a;
    int tempb = b;
    while(tempa){
        tempa = tempa/tempb;
        currMiniOps++;
    }
    ops = currMiniOps;

    while(ops <= currMiniOps){
        i++;
        if(b>60) break;
        int tempMiniOps = 0;
        tempMiniOps+=i;
        b++;
        int tempa = a;
        while(tempa){
            tempa = tempa/b;
            tempMiniOps++;
        }
        if(tempMiniOps<currMiniOps) currMiniOps = tempMiniOps;
        ops = tempMiniOps;
    }

    cout<<currMiniOps<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

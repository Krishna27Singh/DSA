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
    long long n, k; cin>>n>>k;

    if (n % 2 == 0) {
            cout << "YES"<<endl;
    } 
    else{
            if (k % 2 == 1 && n >= k) cout << "YES"<<endl;
            else cout << "NO"<<endl;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

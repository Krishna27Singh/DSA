#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n; char c; cin>>c;
    string s; cin>>s;

    vector<int>ans;
        bool ok = true;
        for(auto x:s){
            if(x != c){
                ok = false;
            }
        }
        if(!ok){
            for(int i=1;i<n+1; i++){
                ok = true;
                for(int j=i;j<n+1; j++){
                    ok &= (s[j-1] == c);
                    j += i-1;
                }
                if(ok){
                    ans.push_back(i);
                    break;
                }
            }
            if(!ok){
                ans.push_back(n);
                ans.push_back(n-1);
            }
        }
        cout<<ans.size()<<"\n";
        for(auto x:ans){
            cout<<x<<" ";
        }

    // if(!noC && s[n-1]==c){
    //     cout<<0<<endl;
    // }
    // else if(!noC && s[n-1]!=c){
    //     cout<<1<<endl;
    //     cout<<n-1<<endl;
    // }
    // else if(noC && s[n-1]==c){
    //     cout<<1<<endl;
    //     cout<<n<<endl;
    // }
    // else if(noC && s[n-1]!=c){
    //     cout<<2<<endl;
    //     cout<<n<<" "<<n-1<<endl;
    // }

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

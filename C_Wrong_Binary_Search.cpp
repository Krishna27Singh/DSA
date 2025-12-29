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
    int n; cin>>n;
    string s; cin>>s;
    if(n>=2 && ((s[0]=='0' && s[1]=='1') || (s[n-2]=='1' && s[n-1]=='0'))){
        cout<<"NO"<<endl;
        return;
    }
    int cnt1 = 0;
    for(auto c: s) if(c == '1') cnt1++;
    if(cnt1 == 0){
        cout<<"YES"<<endl;
        for(int i = n; i>=1; i--) cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(cnt1 == 1){
        cout<<"YES"<<endl;
        int one_pos = s.find('1') + 1;
        int fill = one_pos-1;
        for(int i = 1; i<one_pos; i++){
            cout<<fill<<" ";
            fill--;
        }
        cout<<one_pos<<" ";
        fill = n;
        for(int i = one_pos+1; i<=n; i++) cout<<fill--<<" ";
        cout<<endl;
        return;
    }
        
    vector<int> stable;
    for(int i = 0; i<n; i++) if(s[i]=='1') stable.push_back(i+1);
    int len = stable.size();
    for(int i = 0; i<len-1; i++){
        if(stable[i+1]-stable[i]==2){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

    int fill = stable[0]-1;
    for(int i = 1; i<stable[0]; i++) cout<<fill--<<" ";
    cout<<stable[0]<<" ";

    for(int i = 1; i<len; i++){
        int fillLen = stable[i]-stable[i-1]-1;
        fill = stable[i]-1;
        for(int j = 0; j<fillLen; j++) cout<<fill--<<" ";
        cout<<stable[i]<<" ";
    }

    fill = n;
    int fillLen = n - stable[len-1];
    for(int i = 0; i<fillLen; i++) cout<<fill--<<" ";
    cout<<endl; 

    // Output
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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

// bool checkPalindrome(string s){
//     int left = 0;
//     int right = s.length() - 1;
//     while(left < right){
//         if(s[left] != s[right]) return false;
//         left++;
//         right--;
//     }
//     return true;
// }

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    // if(checkPalindrome(s)){
    //     cout<<0<<endl;
    //     cout<<""<<endl;
    //     return;
    // }

    vector<int> ans;
    for(int i = 0; i<n; i++){
        if(s[i]=='0') ans.push_back(i+1);
    }

    if(ans.size() == 0){
        cout<<0<<endl;
        cout<<""<<endl;
        return;
    }

    cout<<ans.size()<<endl;
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

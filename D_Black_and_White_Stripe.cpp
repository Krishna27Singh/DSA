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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    

    int noOfBlack = 0;
    for(int i = 0; i<k; i++){
        if(s[i]=='B') noOfBlack++;
    }

    int minWhite = INT_MAX;
    for(int ptr2 = k-1; ptr2<n; ptr2++){
        int ptr1 = ptr2 - k + 1;
        int currentWhite = k - noOfBlack;
        minWhite = min(minWhite, currentWhite);
        if(ptr2+1 < n){
            if(s[ptr1]=='B') noOfBlack--;
            if(s[ptr2+1]=='B') noOfBlack++;
        }
    }
    cout<<minWhite<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    string s; cin>>s;
    string t; cin>>t;

    unordered_map<char, int> sFreq;
    unordered_map<char, int> tFreq;
    for(auto c: s) sFreq[c]++;
    for(auto c: t) tFreq[c]++;

    string tWithoutS = "";
    for(auto &it : tFreq){
        char tChar = it.first;
        int tCharFreq = it.second;
        int sCharFreq = sFreq[tChar];

        if(sCharFreq > tCharFreq){
            cout<<"Impossible"<<endl;
            return;
        }

        it.second -= sCharFreq;
    }

    for(auto &it : tFreq){
        char tChar = it.first;
        int tCharFreq = it.second;
        for(int i = 0;i < tCharFreq;i++){
            tWithoutS += tChar;
        }
    }

    sort(tWithoutS.begin(), tWithoutS.end());

    string ans = "";
    int ptr1 = 0;
    int ptr2 = 0;

    while(ptr1 < s.size() && ptr2 < tWithoutS.size()){
        if(s[ptr1] <= tWithoutS[ptr2]){
            ans += s[ptr1];
            ptr1++;
        }
        else{
            ans += tWithoutS[ptr2];
            ptr2++;
        }
    }

    while(ptr1 < s.size()){
        ans += s[ptr1];
        ptr1++;
    }

    while(ptr2 < tWithoutS.size()){
        ans += tWithoutS[ptr2];
        ptr2++;
    }

    // if(ptr!=s.size()){
    //     while(ptr < s.size()){
    //         ans += s[ptr];
    //         ptr++;
    //     }
    // }

    for(auto i: ans) cout<<i;
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

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
    int n, k; cin>>n>>k;
    string s; cin>>s;

    int cnt = 0;
    vector<int> continuousZeros;
    for(int i = 0;i < n;){
        if(s[i] == '1'){
            i++;
            continue;
        }
        int j = i;
        while(j < n && s[j] == '0') j++;
        continuousZeros.push_back(j - i);
        i = j;
    }

    if(s[0]=='0'){
        cnt += continuousZeros[0];
        for(int i = 1; i<continuousZeros.size(); i++){
            if(continuousZeros[i] > k) cnt += continuousZeros[i]-k;
        }
    }
    else{
        for(int i = 0; i<continuousZeros.size(); i++){
            if(continuousZeros[i] > k) cnt += continuousZeros[i]-k;
        }
    }

    // for(auto i: continuousZeros) cout<<i<<" ";
    // cout<<endl;

    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

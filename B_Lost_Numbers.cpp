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
#include <numeric>
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int a[6] = {4, 8, 15, 16, 23, 42};
    unordered_map<int, pair<int, int>> mpp;
    for(int i = 0; i<6; i++){
        for(int j = i+1; j<6; j++){
            mpp[a[i]*a[j]] = {a[i], a[j]};
        }
    }

    vector<int> ans(6);

    cout<<"? "<<1<<" "<<2<<endl;
    cout.flush();
    int x; cin>>x;
    auto firstSecond = mpp[x];

    cout<<"? "<<2<<" "<<3<<endl;
    cout.flush();
    cin>>x;
    auto secondThird = mpp[x];

    if(firstSecond.first == secondThird.first || firstSecond.first == secondThird.second){
        ans[0] = firstSecond.second;
        ans[1] = firstSecond.first;
        ans[2] = secondThird.first == firstSecond.first ? secondThird.second : secondThird.first;
    }
    else{
        ans[0] = firstSecond.first;
        ans[1] = firstSecond.second;
        ans[2] = secondThird.first == firstSecond.second ? secondThird.second : secondThird.first;
    }

    cout<<"? "<<3<<" "<<4<<endl;
    cout.flush();
    cin>>x;
    auto thirdFourth = mpp[x];
    ans[3] = thirdFourth.first == ans[2] ? thirdFourth.second : thirdFourth.first;

    cout<<"? "<<4<<" "<<5<<endl;
    cout.flush();
    cin>>x;
    auto fourthFifth = mpp[x];
    ans[4] = fourthFifth.first == ans[3] ? fourthFifth.second : fourthFifth.first;

    unordered_map<int, int> pres;
    for(int i = 0; i<5; i++) pres[ans[i]] = 1;
    for(int i = 0; i<6; i++){
        if(pres.find(a[i]) == pres.end()){
            ans[5] = a[i];
            break;
        }
    }

    cout<<"! ";
    for(int i = 0; i<6; i++) cout<<ans[i]<<" ";
    cout<<endl;
    cout.flush();

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

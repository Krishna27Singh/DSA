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
Anna goes first

Anna's turn -> choose a number in a and reverse the digit, size remains same
Sasha's turn -> choose two number and concatanate them in any order and insert into the array, the size of the array decreases by 1

shasha's goal -> last integer should be >= 10em
anna's goal -> last integer shoudl be < 10em

anna will choose the largest integer 

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    // int temp = m;
    // int target = 1;
    // while(temp--) target*=10;

    // if(n == 1){
    //     if(a[0] >= target) cout<<"Sasha"<<endl;
    //     else cout<<"Anna"<<endl;
    //     return;
    // }

    int initialPow = -1;
    for(int i = 0; i<n; i++){
        int temp = a[i];
        while(temp){
            initialPow++;
            temp /= 10;
        }
    }
    // cout<<"initial: "<<initialPow<<endl;

    vector<int> endingZeros(10, 0);

    for(int i = 0; i<n; i++){
        int cntEndingZeros = 0;
        int temp = a[i];
        while(temp % 10 == 0){
            temp /= 10;
            cntEndingZeros++;
        }
        endingZeros[cntEndingZeros]++;
    }

    // for(int i = 0; i<10; i++) cout<<i<<" "<<endingZeros[i]<<endl;

    bool Anna = true;
    for(int zeros = 9; zeros>=0; zeros--){
        int nums = endingZeros[zeros];
        if(nums == 0) continue;
        int powLost;
        if(Anna){
            powLost = (nums - nums/2)*zeros;
            if(nums%2) Anna = false;
        }
        else{
            powLost = (nums/2)*zeros;
            if(nums%2) Anna = true;
        }
        // cout<<"powLost: "<<powLost<<endl;
        initialPow -= powLost;
    }

    // cout<<"final: "<<initialPow<<endl;

    // m++;
    if(initialPow >= m) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;



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

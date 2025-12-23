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

int Query1(int l, int r){
    cout<<1<<" "<<l<<" "<<r<<endl;
    int originalSum; cin>>originalSum;
    return originalSum;
}

int Query2(int l, int r){
    cout<<2<<" "<<l<<" "<<r<<endl;
    int modifiedSum; cin>>modifiedSum;
    return modifiedSum;
}

void solve(){
    int n; cin>>n;

    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;
    int l = -1;

    while(s<e){
        //check if l is present in the left half
        int originalSum = Query1(s+1, mid+1);
        int modifiedSum = Query2(s+1, mid+1);
        int difference = originalSum - modifiedSum;
        if(difference == 0){
            //l is not present in left half
            s = mid + 1;
        }
        else{
            //l is present in left half
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    l = s;

    int r = l + Query2(1,n) - Query1(1,n) - 1; 

    cout<<"!"<<" "<<l+1<<" "<<r+1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

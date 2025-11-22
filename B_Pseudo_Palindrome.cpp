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
    int n, d; cin>>n>>d;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    if(n==1){
        cout<<"YES"<<endl;
        return;
    }

    if(n%2==0){
        for(int i = 0; i<n-1; i+=2){
            if(abs(a[i]-a[i+1]) > d){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
    else{
        for(int skip = 0; skip<n; skip+=2){
            bool check = false;
            for(int i = 0; i<n-1; i+=2){
                if(i==skip){
                    i--;
                    continue;
                }
                if(abs(a[i]-a[i+1]) > d){
                    check = true;
                    break;
                }
            }
            if(!check){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}

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
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int q; cin>>q;
    vector<int> l(q), r(q);
    for(int i = 0; i<q; i++) cin>>l[i]>>r[i];

    // vector<int> prefix(n+1, 0);
    // for(int i = 1; i<=n; i++){
    //     prefix[i] = prefix[i-1] + a[i-1];
    // }

    vector<int> nextDiff(n, -1);
    for(int i = n-2; i >= 0; i--){
        if(a[i] != a[i+1]) nextDiff[i] = i+1;
        else nextDiff[i] = nextDiff[i+1];
    }


    //quries
    for(int i = 0; i<q; i++){
        // int left = l[i]-1;
        // int right = r[i]-1;
        // if(left == right){
        //     cout<<-1<<" "<<-1<<endl;
        //     continue;
        // }
        // if(a[left] != a[right]){
        //     cout<<left+1<<" "<<right+1<<endl;
        //     continue;
        // }
        // if(prefix[right+1]-prefix[left] == a[left]*(right-left+1)){
        //     cout<<-1<<" "<<-1<<endl;
        //     continue;
        // }

        // int low = left; 
        // int high = right;
        // int mid = low + (high-low)/2;

        // while(low < high){
        //     if(prefix[mid+1]-prefix[left] != a[left]*(mid-left+1)){
        //         high = mid;
        //     }
        //     else{
        //         low = mid + 1;
        //     }
        //     mid = low + (high - low)/2;
        // }

        // if(low!=left) cout<<left+1<<" "<<low+1<<endl;
        // else cout<<low+1<<" "<<right+1<<endl;
        if(nextDiff[l[i]-1] != -1 && nextDiff[l[i]-1] <= r[i]-1){
            cout<<l[i]<<" "<<nextDiff[l[i]-1]+1<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }

    }
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
